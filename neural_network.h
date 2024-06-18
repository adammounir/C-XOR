#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define numInput 2
#define numHidden  4
#define numOutput  1

double expectedLayer[numOutput];

#ifndef FRONT_PROPAGATION_
#define FRONT_PROPAGATION_
//------------------------------------------------------------------------//
// DECLARATIONS OF "front_propagation.c" FUNCTIONS AND VECTORS/LENGTHS
//------------------------------------------------------------------------//


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
double randomnumber();

//Ranges x between 0 and 1
double sigmoid(double x);


//Assigns random values to a matrix
void assignRandomToMatrix(size_t currentdim, size_t prevdim, double layer[currentdim][prevdim]);


//Assigns random values to a vector
void assignRandomToVector(double layer[], size_t layerSize);


//Computes current layer values according to the previous one
void layerValues(double previousValues[], double currentValues[], double currentBias[], size_t sizePreviousValues, size_t sizeCurrentValues,double previousToCurrentWeights[][sizePreviousValues]);



void frontPropagation();
#endif


#ifndef BACK_PROPAGATION_  /* Include guard */
#define BACK_PROPAGATION_ 

//------------------------------------------------------------------------//
// DECLARATIONS OF "back_propagation.c" FUNCTIONS AND VECTORS/LENGTHS
//------------------------------------------------------------------------//

/*-----------------------------------------------------------------------------*/
//2 DIMENSIONS : 1ST CONTAINS N VALUES AND 2ND CONTAINS WEIGHTS LINKED TO THE Nth NEURON

double gradWeightsHiddenToOutput[numOutput][numHidden];
double gradWeightsInputToHidden[numHidden][numInput];

/*-----------------------------------------------------------------------------*/
//ARRAYS THAT CONTAINS BIASES GRADIENTS FOR THE OUPUT AND THE HIDDEN LAYER

double gradBiasesOuputLayer[numOutput];
double gradBiasesHiddenLayer[numHidden];




// ∂C/∂wl = (∂il/∂wl) * (∂ol1/∂il) * (∂C/∂ol1)
void computeGradientToLayer(double expectedLayer[]);


void applyGradientToLayer();


double costFunction(double lastLayer[], double expextedValuesLayer[], size_t sizelastLayer);

#endif



