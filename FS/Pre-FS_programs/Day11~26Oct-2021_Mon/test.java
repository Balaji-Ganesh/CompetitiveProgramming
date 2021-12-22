import java.util.Scanner;
class test{

	public static int flipBits_v2(int number){
        int result=0;
        while(number>0){
            result <<= 1;
            if((number &1) == 1)
                result =result+ 0;
            else
                result = result+1;
            number /= 2;
        }
        return result;
    }

	public static void main(String [] args){
		Scanner scanner = new Scanner(System.in);
		System.out.println(scanner.nextInt());
	}
}
