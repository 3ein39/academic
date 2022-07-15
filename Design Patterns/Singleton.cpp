#include<iostream>
#include<vector>
using namespace std;

/*

 - Saying that we need only ONE instance from this class, may trigger what?
 - Static object: Shared object among all instances
 - Now let's create a static instance to be shared
 - But still users can create objects!
 - The trick is to make the class constructor private!
 - This way no one can create objects!
 - But???? Ok, give him a function to return your static object

 - You just learned Singleton Design Pattern :)
    it is all about having one shared instance of a class across all users
    i.e. the class is a singleton, optimized performance, no need to create a new object every time you need it
    it is a way to ensure that only one instance of a class is created
    and that instance is accessible to all users of the class
 */

class ConfigurationManger {
private:
    string configuration_path;
    vector<string> servers_ips;
    string aws_service_url;
    // Other heavy data
    bool is_loaded = false;

    // create pointer for shared instance
    static ConfigurationManger* instance;
    // private constructor to not allowing users to create instance of this class
    ConfigurationManger(string configuration_path) :
            configuration_path(configuration_path) {
    }
public:
    // create public static (shared) method to get the shared instance
    static ConfigurationManger* getInstance(const string& path){
        if (instance == nullptr) {
            instance = new ConfigurationManger(path);
        }
        return instance;
    }
    void Load() {
        if (is_loaded)
            return;
        // some heavy load
        cout << "Lazy loading\n";
        servers_ips.push_back("10.20.30.40");
        servers_ips.push_back("10.20.30.41");
        servers_ips.push_back("10.20.30.42");
        aws_service_url = "https://dynamodb.us-west-2.amazonaws.com";
        is_loaded = true;
    }
    string GetAwsServiceUrl() {
        Load();
        return aws_service_url;
    }
    static void Destroy() {
        if (instance != nullptr) {
            delete instance;
            instance = nullptr;
            cout << "Destroyed\n";
        } else
            cout << "Already destroyed\n";
    }
};
ConfigurationManger* ConfigurationManger::instance = nullptr;

void f1() {
    ConfigurationManger* mgr = ConfigurationManger::getInstance("/home/moustafa/conf_info.txt");
    cout<<mgr->GetAwsServiceUrl()<<"\n";
}

void f2() {
    ConfigurationManger* mgr = ConfigurationManger::getInstance("/home/moustafa/conf_info.txt");
    cout<<mgr->GetAwsServiceUrl()<<"\n";
}

int main() {
    f1();
    f2();

    return 0;
}
