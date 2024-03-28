#include <stdio.h>

#define COMMENT_LENGTH 100

typedef struct {
    // Define your struct members here
} VimosImage;

typedef struct {
    // Define your struct members here
} VimosPort;

int readDoubleDescriptor(/* arguments */) {
    // Implement the readDoubleDescriptor function here
    return 0;
}

VimosPort* getPorts(/* arguments */) {
    // Implement the getPorts function here
    return NULL;
}

void deletePortList(/* arguments */) {
    // Implement the deletePortList function here
}

double getMeanGainFactor(VimosImage *image) {
    char comment[COMMENT_LENGTH];
    int i, nports;
    double gain;
    double sumGain = 0.0;
    VimosPort *ports;

    ports = getPorts(image, &nports);

    if (ports) {
        sumGain = 0.0;

        for (i = 1; i <= nports; i++) {
            if (readDoubleDescriptor(image->descs, pilTrnGetKeyword("Adu2Electron", i), &gain, comment) == 0) {
                gain = -1.0;
                return gain;
            }

            sumGain += gain;
        }

        gain = sumGain / nports;
        deletePortList(ports);
    }

    return gain;
}

int main() {
    // Create a VimosImage instance and pass it to getMeanGainFactor function
    VimosImage image;
    double meanGain = getMeanGainFactor(&image);

    printf("Mean Gain: %lf\n", meanGain);

    return 0;
}
