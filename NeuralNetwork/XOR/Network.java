/**
 * Created by trustgeek on 10/17/2017 {09:08 PM}.
 */

public class Network {
    private final int inputCount;
    private final int hiddenCount;
    private final int outputCount;
    private final double learnRate;
    private final double momentum;
    private final int neuronCount;
    private final int weightCount;
    private final double[] matrixDelta;
    private double[] fire;
    private double[] thresholds;
    private double[] matrix;
    private double[] error;
    private double[] actualMatrixDelta;
    private double[] errorDelta;
    private double globalError;
    private double[] thresholdDelta;
    private double[] actualThresholdDelta;

    public Network(int numOfInputs, int numOfHiddens, int numOfOutputs, double learnRate, double momentum) {
        this.inputCount = numOfInputs;
        this.hiddenCount = numOfHiddens;
        this.outputCount = numOfOutputs;

        this.learnRate = learnRate;
        this.momentum = momentum;

        this.neuronCount = inputCount + hiddenCount + outputCount;
        this.weightCount = inputCount * hiddenCount + hiddenCount * outputCount;

        this.fire = new double[neuronCount]; // holds fired neurons
        this.matrix = new double[weightCount]; // holds matrix for weights
        this.thresholds = new double[neuronCount];
        this.error = new double[neuronCount];
        this.actualMatrixDelta = new double[weightCount];
        this.errorDelta = new double[neuronCount];
        this.matrixDelta = new double[weightCount];
        this.thresholdDelta = new double[neuronCount];
        this.actualThresholdDelta = new double[neuronCount];
        reset();
    }

    public double[] computeOutputs(double input[]) {
        final int hiddenIndex = inputCount;
        final int outIndex = inputCount + hiddenCount;

        int i = 0;
        for (i = 0; i < inputCount; i++) {
            fire[i] = input[i];
        }

        // first layer output to second / Hidden layer
        int inx = 0;
        for (i = hiddenIndex; i < outIndex; i++) {
            double sum = thresholds[i];
            for (int j = 0; j < inputCount; j++)
                sum += fire[j] * matrix[inx++];
            fire[i] = sigmoid(sum);
        }

        // output for hidden layer
        double result[] = new double[outputCount];
        for (i = outIndex; i < neuronCount; i++) {
            double sum = thresholds[i];
            for (int j = hiddenIndex; j < outIndex; j++) {
                sum += fire[j] * matrix[inx++];
            }
            fire[i] = sigmoid(sum);
            result[i - outIndex] = fire[i];
        }
        return result;
    }

    private double sigmoid(double sum) {
        return 1.0 / (1 + Math.exp(-1.0 * sum));
    }

    public void calculateError(double actual[]) {
        final int hiddenIndex = inputCount;
        final int outputIndex = inputCount + hiddenCount;

        // clear hidden layer errors
        for (int i = inputCount; i < neuronCount; i++) {
            error[i] = 0;
        }

        // layer errors and deltas for output layer
        for (int i = outputIndex; i < neuronCount; i++) {
            error[i] = actual[i - outputIndex] - fire[i];
            globalError += error[i] * error[i];
            errorDelta[i] = error[i] * fire[i] * (1 - fire[i]);
        }

        // hidden layer error
        int hiddenError = inputCount * hiddenCount;

        for (int i = outputIndex; i < neuronCount; i++) {
            for (int j = hiddenIndex; j < outputIndex; j++) {
                actualMatrixDelta[hiddenError] += errorDelta[i] * fire[j];
                error[j] += matrix[hiddenError] * errorDelta[i];
                hiddenError++;
            }
            actualThresholdDelta[i] += errorDelta[i];
        }

        // hidden layer deltas
        for (int i = hiddenIndex; i < outputIndex; i++) {
            errorDelta[i] = error[i] * fire[i] * (1 - fire[i]);
        }

        // input layer errors
        hiddenError = 0; // offset into weight array
        for (int i = hiddenIndex; i < outputIndex; i++) {
            for (int j = 0; j < hiddenIndex; j++) {
                actualMatrixDelta[hiddenError] += errorDelta[i] * fire[j];
                error[j] += matrix[hiddenError] * errorDelta[i];
                hiddenError++;
            }
            actualThresholdDelta[i] += errorDelta[i];
        }
    }

    public void learn() {
        // process matrix
        for (int i = 0; i < matrix.length; i++) {
            matrixDelta[i] = (learnRate * actualMatrixDelta[i]) + (momentum * matrixDelta[i]);
            matrix[i] += matrixDelta[i];
            actualMatrixDelta[i] = 0;
        }
        // process the thresholds
        for (int i = inputCount; i < neuronCount; i++) {
            thresholdDelta[i] = learnRate * actualThresholdDelta[i] + momentum * actualThresholdDelta[i];
            thresholds[i] += thresholdDelta[i];
            actualThresholdDelta[i] = 0;
        }
    }

    public void reset() {
        int i;

        for (i = 0; i < neuronCount; i++) {
            thresholds[i] = 0.5 - (Math.random());
            thresholdDelta[i] = 0;
            actualThresholdDelta[i] = 0;
        }
        for (i = 0; i < matrix.length; i++) {
            matrix[i] = 0.5 - (Math.random());
            matrixDelta[i] = 0;
            actualMatrixDelta[i] = 0;
        }
    }

    public double getError(int len) {
        double err = Math.sqrt(globalError / (len * outputCount));
        globalError = 0; // clear the accumulator
        return err;
    }
}