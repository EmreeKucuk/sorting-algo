import java.io.FileWriter;
import java.util.Scanner;
import java.io.File;
import java.io.*;


public class Main {
    public static void main(String[] args) {
//file creation
        File myFile = new File("C:\\Users\\emrek\\OneDrive\\Masaüstü\\myFile\\emrekucuk.txt");
        try{
            if (myFile.createNewFile()) {
                System.out.println("File Created");
            }
            else {
                System.out.println("File already exist");
            }
        } catch (IOException e){
            throw new RuntimeException(e);
        }
        System.out.println("\n--------------------\n");
//writing into a file
        try{
            BufferedWriter myWriter = new BufferedWriter(new FileWriter("C:\\Users\\emrek\\OneDrive\\Masaüstü\\myFile\\emrekucuk.txt"));
            Scanner scanner = new Scanner(System.in);
            System.out.println("You have 5 line to write, you may write: ");
            for(int i=0;i<5;i++){
            String content = scanner.nextLine();
            myWriter.write(content + "\n");}
            myWriter.close();
            System.out.println("Succesfully written");
        }
        catch (IOException e){
            System.out.println("An error has occured while writing.");
            e.printStackTrace();
        }
        System.out.println("\n--------------------\n");
//reading the file
        System.out.println("The contents of the file :");
        try{
            File file = new File("C:\\Users\\emrek\\OneDrive\\Masaüstü\\myFile\\emrekucuk.txt");
            Scanner scan = new Scanner(file);
            while (scan.hasNextLine()){
                String data = scan.nextLine();
                System.out.println(data);
            }
            scan.close();
        } catch (FileNotFoundException e){
            System.out.println("An error occured while reading");
            e.printStackTrace();
        }
        System.out.println("\n--------------------\n");
//file info
        File file = new File("C:\\Users\\emrek\\OneDrive\\Masaüstü\\myFile\\emrekucuk.txt");
        if(file.exists()){
            System.out.println("The name of the file: " + file.getName());
            System.out.println("The absolute path of the file: " + file.getAbsolutePath());
            System.out.println("Is file writeable: " + file.canWrite());
            System.out.println("Is file readable: " + file.canRead());
            System.out.println("The size of the file: " + file.length());
        }
        else{
            System.out.println("File does not exist.");
        }
        System.out.println("\n--------------------\n");
//file deletion
 /*       File fileDel = new File("C:\\Users\\emrek\\OneDrive\\Masaüstü\\myFile\\emrekucuk.txt");
        if(fileDel.delete()){
            System.out.println("The "+fileDel.getName() + " file has been deleted succesfully");
        }
        else{
            System.out.println("An error has occured");
        }
*/
    }
}