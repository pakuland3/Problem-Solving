import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Scanner;

class p{
    int x,y;
    p(int x, int y){
        this.x=x;
        this.y=y;
    }
}

public class p12781{
    public static void main(String args[]) throws Exception{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb=new StringBuilder();
        Scanner sc=new Scanner(System.in);
        // StringTokenizer st=new StringTokenizer();
        p a[]=new p[4];
        int x,y;
        for(int i=0;i<4;i++){
            x=sc.nextInt();
            y=sc.nextInt();
            a[i]=new p(x,y);
        }
        if(ccw(a[0],a[1],a[2])*ccw(a[0],a[1],a[3])<0) System.out.println(1);
        else System.out.println(0);
    }
    static int ccw(p a, p b, p c){
        int res=a.x*b.y+b.x*c.y+c.x*a.y-(a.x*c.y+b.x*a.y+c.x*b.y);
        if(res>0) return 1;
        if(res<0) return -1;
        return 0;
    }
}