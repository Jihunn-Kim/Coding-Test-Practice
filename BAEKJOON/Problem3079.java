import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Problem3079 {
    static int N, M;
    static long inputs[];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        long maxTime = 0;
        
        inputs = new long[N + 1];
        for (int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            inputs[i] = Long.parseLong(st.nextToken());
            if (maxTime < inputs[i])
                maxTime = inputs[i];
        }

        long low = 1;
        long high = maxTime * (long) (M / N);
        while (low <= high) {
            long mid = (low + high) / 2;
            long temp = 0;
            for (int i = 0; i < N; ++i)
                temp += (long) (mid / inputs[i]);
            
            if (temp >= M) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        System.out.println(low);
    }

}
 