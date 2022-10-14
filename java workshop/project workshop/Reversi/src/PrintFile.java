import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;

public class PrintFile {

    static void printFile(File file){
        try{
            BufferedReader br= new BufferedReader(new FileReader(file) );
            String s;
            while((s= br.readLine())!= null ){
                System.out.println(s+ "CS217");
            }
        }catch (Exception e){

        }
    }

    static void printFileReverse(File file){
        try{
            BufferedReader br= new BufferedReader(new FileReader(file) );
            String s;
            while((s= br.readLine())!= null ){
                System.out.println(s+ "CS217");
            }
        }catch (Exception e){

        }
    }

    public static void main(String[] args) {
        printFile(new File("./src/CS217.txt") );
    }
}
