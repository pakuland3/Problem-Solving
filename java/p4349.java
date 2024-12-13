import java.io.BufferedReader;
import java.io.InputStreamReader;
public class p4349{
    public static void main(String args[]) throws Exception{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb=new StringBuilder();
        // StringTokenizer st=new StringTokenizer();
        int c=Integer.parseInt(br.readLine());
        while((c--)!=0){
            int n=Integer.parseInt(br.readLine());
            int x=n,y=1,z=1;
            int ans=2*(x*y+y*z+x*z);
            for(int i=1;i<=Math.sqrt(n);i++){
                if(n%i==0){
                    x=i;
                    int tmp=n/x;
                    for(int j=1;j<=Math.sqrt(tmp);j++){
                        if(tmp%j==0){
                            y=j;
                            z=tmp/j;
                            ans=Math.min(ans,2*(x*y+y*z+x*z));
                        }
                    }
                }
            }
            sb.append(ans).append('\n');
        }
        System.out.print(sb);
    }
}