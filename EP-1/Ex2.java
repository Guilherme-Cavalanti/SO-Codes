import java.lang.Thread;

public class Ex2 {
    public static void main(String[] args) {
        //Booleano para sincornizar a execução das Threads
        boolean[] next = { false };

        //Criação da primeira Thread
        Thread t1 = new Thread(() -> {
            synchronized (next) {
                System.out.println("Hello World");
        }});

        //Criação da segunda Thread
        Thread t2 = new Thread(() -> {
            synchronized (next) {
                System.out.println("Hello World");
        }});

        //Criação da terceira Thread
        Thread t3 = new Thread(() -> {
            synchronized (next) {
                System.out.println("Hello World");
        }});

        //Criação da quarta Thread
        Thread t4 = new Thread(() -> {
            synchronized (next) {
                System.out.println("Hello World");
        }});

        // Chamada das 4 Threads
      
        t1.start();
        t2.start();
        t3.start();
        t4.start();
    }
}