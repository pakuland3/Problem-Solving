import java.io.BufferedReader;
import java.io.InputStreamReader;

public class p10384{
    public static void main(String args[]) throws Exception{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb=new StringBuilder();
        // StringTokenizer st=new StringTokenizer();
        int n=Integer.parseInt(br.readLine());
        for(int i=0;i<n;i++){
            String a=br.readLine();
            int cnt[]=new int[26];
            for(int j=0;j<26;j++) cnt[j]=0;
            for(int j=0;j<a.length();j++){
                char b=a.charAt(j);
                if('a'<=b && b<='z') cnt[b-'a']++;
                if('A'<=b && b<='Z') cnt[b-'A']++;
            }
            boolean b1=true,b2=true,b3=true;
            for(int j=0;j<26;j++){
                if(cnt[j]<1) b1=false;
                if(cnt[j]<2) b2=false;
                if(cnt[j]<3) b3=false;
            }
            sb.append("Case "+(i+1)+": ");
            if(b3) sb.append("Triple pangram!!!");
            else if(b2) sb.append("Double pangram!!");
            else if(b1) sb.append("Pangram!");
            else sb.append("Not a pangram");
            sb.append('\n');
        }
        System.out.print(sb);
    }
}