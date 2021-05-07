import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Problem2564 {
    static int width, height, N, a, b, sxy;
    static int inputs[];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        width = Integer.parseInt(st.nextToken());
        height = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        inputs = new int[N];
        for(int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            if (a == 1)
                inputs[i] = height + b;
            else if (a == 2)
                inputs[i] = 2 * height + 2 * width - b;
            else if (a == 3)
                inputs[i] = height - b;
            else if (a == 4)
                inputs[i] = height + b + width;
        }

        st = new StringTokenizer(br.readLine());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        if (a == 1)
            sxy = height + b;
        else if (a == 2)
            sxy = 2 * height + 2 * width - b;
        else if (a == 3)
            sxy = height - b;
        else if (a == 4)
            sxy = height + b + width;

        int ans = 0;
        for(int i = 0; i < N; ++i) {
            int temp = Math.abs(sxy - inputs[i]);
            ans += (temp > (width + height)) ? 2 * (width + height) - temp : temp;
        }

        System.out.println(ans);
    }

}