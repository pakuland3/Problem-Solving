import java.io.BufferedReader;
import java.io.InputStreamReader;
public class p25705{
    public static void main(String args[]) throws Exception{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb=new StringBuilder();
        // StringTokenizer st=new StringTokenizer();
        int n=Integer.parseInt(br.readLine());
        String a=br.readLine();
        int m=Integer.parseInt(br.readLine());
        String b=br.readLine();
        int p=n-1;
        int res=0;
        for(int i=0;i<m;i++){
            boolean flag=false;
            for(int j=0;j<n;j++){
                p++;
                res++;
                if(p==n) p=0;
                if(a.charAt(p)==b.charAt(i)){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                System.out.println(-1);
                System.exit(0);
            }
        }
        System.out.println(res);
    }
}