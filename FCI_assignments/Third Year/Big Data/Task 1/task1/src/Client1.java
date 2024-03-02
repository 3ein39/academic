import java.io.*;
import java.net.*;

public class Client1 {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 1234);
            ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());

            int[][] matrix = {{1, 2}, {3, 4}};
            out.writeObject(matrix);
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}