//                  INCLUDE LIBRARY
#include "neural_network.h"

/*--------------------------------------------------------*/
//      DEFINES NUMBER OF NEURONS IN A LAYER


/*--------------------------------------------------------*/
//      DEFINES ARRAYS REPRESENTING LAYERS OUTPUT VALUES

double hiddenLayer[numHidden];
double inputLayer[numInput];
double outputLayer[numOutput];


/*--------------------------------------------------------*/
//      DEFINES THE WEIGHTS VALUES

double inputToHidden[numHidden][numInput];
double hiddenToOutput[numOutput][numHidden];

/*--------------------------------------------------------*/
//      DEFINES THE BIAS VALUES

double hiddenBias[numHidden];
double outputBias[numOutput];


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/




//Generates a random number between 0 and 1
double randomnumber()
{
    return ((double)rand() / ((double) RAND_MAX));
}

//Ranges x between 0 and 1
double sigmoid(double x)
{
    return 1/(1+exp(-x));
}


//Assigns random values to a matrix
void assignRandomToMatrix(size_t currentdim, size_t prevdim, double layer[currentdim][prevdim])
{
    for(size_t i=0; i<currentdim; i++)
    {
       for(size_t j=0; j<prevdim; j++)
            layer[i][j] = randomnumber();
    }
}


//Assigns random values to a vector
void assignRandomToVector(double layer[], size_t layerSize)
{
    for(size_t i=0; i<layerSize; i++)
        layer[i] = randomnumber();
    
}


//Computes current layer values according to the previous one
void layerValues(double previousValues[], double currentValues[], double currentBias[], size_t sizePreviousValues, size_t sizeCurrentValues,double previousToCurrentWeights[][sizePreviousValues])
{
    for(size_t i=0; i<sizeCurrentValues; i++)
    {
        currentValues[i] = 0;
        for(size_t j=0; j<sizePreviousValues; j++)
        {
            //neuron += Σ(values * weight)
            currentValues[i] += previousValues[j] * previousToCurrentWeights[i][j];
        }
        //add bias to the neuron value
        currentValues[i] += currentBias[i];
        
        //ranges the value between 0 and 1
        currentValues[i] = sigmoid(currentValues[i]);
    }
}


//Function that makes the front propagation 
void frontPropagation()
{
    //Compute values of the hidden layer
    layerValues(inputLayer, hiddenLayer, hiddenBias, numInput, numHidden, inputToHidden);

    //Compute values of the output layer
    layerValues(hiddenLayer, outputLayer, outputBias, numHidden, numOutput, hiddenToOutput);

}







