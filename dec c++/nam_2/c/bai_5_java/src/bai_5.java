import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

public class bai_5 {

    public static void main(String[] args) {
        LinkedList<String> linkedList = new LinkedList<>();
        String value="";
        while (true){
            System.out.print("nhap phan tu: ");
            Scanner scanner =new Scanner(System.in);
            value = scanner.nextLine();
            linkedList.add(value);
            System.out.print("co nhap nua khong(Y/N): ");
            char isCheck;
            value = scanner.nextLine();
            isCheck=value.charAt(0);
            if (isCheck=='N'||isCheck=='n') break;
        }
        Iterator<String> interanor = linkedList.iterator();
        System.out.println("Cac phan tu da nhap la: ");
        while (interanor.hasNext()){
            value = (String) interanor.next();
            System.out.print(value + "\t");
        }

    }
}
