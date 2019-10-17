import java.text.NumberFormat;
import java.util.Arrays;

/**
 * Created by trustgeek on 10/17/2017 {09:08 PM}.
 */

public class XorTest {
    public static void main(String args[]) {
        double xorInput[][] =
                {
                        {0.0, 0.0},
                        {1.0, 0.0},
                        {0.0, 1.0},
                        {1.0, 1.0}
                };

        double actualResult[][] = {{0.0}, {1.0}, {1.0}, {0.0}};

        System.out.println("xorInput = " + Arrays.toString(xorInput));

        NumberFormat percentFormat = NumberFormat.getPercentInstance();
        percentFormat.setMinimumFractionDigits(4);

        Network xorNetwork = new Network(2, 3, 1, 0.7, 0.9);
        for (int i = 0; i < 10000; i++) {
            for (int j = 0; j < xorInput.length; j++) {
                xorNetwork.computeOutputs(xorInput[j]);
                xorNetwork.calculateError(actualResult[j]);
                xorNetwork.learn();
            }
            System.out.println(" Trial #" + i + ", Error : " + percentFormat.format(xorNetwork.getError(xorInput.length)));
        }

        System.out.println("\nTesting for output: ");
        for (int i = 0; i < xorInput.length; i++) {
            double out[] = xorNetwork.computeOutputs(xorInput[i]);

            for (int j = 0; j < xorInput[0].length; j++) {
                System.out.print(xorInput[i][j] + " ");
            }
            System.out.println(" = " + out[0]);
        }
    }
}