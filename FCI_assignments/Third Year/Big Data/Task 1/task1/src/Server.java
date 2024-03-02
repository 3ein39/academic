import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) {
        System.out.println("Server started");
        try {
            ServerSocket serverSocket = new ServerSocket(1234);
            Socket clientSocket1 = serverSocket.accept();
            ObjectInputStream in1 = new ObjectInputStream(clientSocket1.getInputStream());
            int[][] matrix1 = (int[][]) in1.readObject();
            System.out.println("Matrix 1 received");
            System.out.println("Matrix 1:");
            for (int[] row : matrix1) {
                for (int num : row) {
                    System.out.print(num + " ");
                }
                System.out.println();
            }


            Socket clientSocket2 = serverSocket.accept();
            ObjectInputStream in2 = new ObjectInputStream(clientSocket2.getInputStream());
            int[][] matrix2 = (int[][]) in2.readObject();
            System.out.println("Matrix 2 received");
            System.out.println("Matrix 2:");
            for (int[] row : matrix2) {
                for (int num : row) {
                    System.out.print(num + " ");
                }
                System.out.println();
            }

            int[][] result = multiplyMatrices(matrix1, matrix2);
            System.out.println("Result:");

            for (int[] row : result) {
                for (int num : row) {
                    System.out.print(num + " ");
                }
                System.out.println();
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    private static int[][] multiplyMatrices(int[][] a, int[][] b) {
        int rows = a.length;
        int columns = b[0].length;
        int[][] result = new int[rows][columns];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                for (int k = 0; k < a[0].length; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        return result;
    }
}