/*-----------------------------------------------------------------------------*/
//                              INCLUDES 

#include "neural_network.h"

/*-----------------------------------------------------------------------------*/
//2 DIMENSIONS : 1ST CONTAINS N VALUES AND 2ND CONTAINS WEIGHTS LINKED TO THE Nth NEURON

double gradWeightsHiddenToOutput[numOutput][numHidden];
double gradWeightsInputToHidden[numHidden][numInput];

/*-----------------------------------------------------------------------------*/
//ARRAYS THAT CONTAINS BIASES GRADIENTS FOR THE OUPUT AND THE HIDDEN LAYER

double gradBiasesOuputLayer[numOutput];
double gradBiasesHiddenLayer[numHidden];




// ∂C/∂wl = (∂il/∂wl) * (∂ol1/∂il) * (∂C/∂ol1)
void computeGradientToLayer(double expectedLayer[])
{
    //Initailzes the secondAndThirdPartArray 
    double secondAndThirdPartArray[numOutput];



    // OUTPUT LAYER GRADIENT 

    for(int nthoutput=0; nthoutput<numOutput; nthoutput++)
    {
        double secondAndThirdPart =    outputLayer[nthoutput]*(1 - outputLayer[nthoutput])*    2*(outputLayer[nthoutput] - expectedLayer[nthoutput]);
        //                             ↑ = second part of gradient                            ↑ = third part of gradient
        
        //Computes the biases gradient values for the output layer
        gradBiasesOuputLayer[nthoutput] = secondAndThirdPart;

        //Computes the secondAndThirdPartArray with its values
        secondAndThirdPartArray[nthoutput] = secondAndThirdPart;


        for (int nthhidden=0; nthhidden<numHidden; nthhidden++)
        {
            double gradWeight = hiddenLayer[nthhidden];
            //                  ↑ = first part of the gradient

            //Multiplies 3 parts of the gradient
            gradWeight *= secondAndThirdPart;

            //Assigns the gradient to the current neuron in the output layer 
            gradWeightsHiddenToOutput[nthoutput][nthhidden] = gradWeight;
        }
    }

    
    //HIDDEN LAYER GRADOENT

    // ∂C/∂wh = (∂ih/∂wh) * (∂oh/∂ih) * (∂C/∂oh)
    for(int nthhidden=0; nthhidden<numHidden; nthhidden++)
    {
        double secondPart = hiddenLayer[nthhidden]*(1 - hiddenLayer[nthhidden]);
        
        for(int nthinput=0; nthinput<numInput; nthinput++)
        {
            double firstPart = inputLayer[nthinput];

            double thirdPart = 0;
            for (int nthoutput=0; nthoutput<numOutput; nthoutput++)
            {
                thirdPart += hiddenToOutput[nthoutput][nthhidden] * secondAndThirdPartArray[nthoutput];
            }
            gradBiasesHiddenLayer[nthhidden] = secondPart * thirdPart;
            gradWeightsInputToHidden[nthhidden][nthinput] = firstPart * secondPart * thirdPart;
        }
    }

}

void applyGradientToLayer()
{
    computeGradientToLayer(expectedLayer);

    for (int nthoutput=0; nthoutput<numOutput ; nthoutput++)
    {
        outputBias[nthoutput] -= gradBiasesOuputLayer[nthoutput];

        for (int nthhidden=0; nthhidden<numHidden ; nthhidden++)
        {
            hiddenToOutput[nthoutput][nthhidden] -= gradWeightsHiddenToOutput[nthoutput][nthhidden];
            hiddenBias[nthhidden] -= gradBiasesHiddenLayer[nthhidden];

            for (int nthinput=0 ; nthinput<numInput ; nthinput++)
            {
                inputToHidden[nthhidden][nthinput] -= gradWeightsInputToHidden[nthhidden][nthinput];
            }

        }
    }
}


double costFunction(double lastLayer[], double expextedValuesLayer[], size_t sizelastLayer)
{
    double cost = 0;
    for (size_t i=0; i<sizelastLayer ;i++)
    {
        cost += (lastLayer[i] - expextedValuesLayer[i]) * (lastLayer[i] - expextedValuesLayer[i]); 
    }
    return cost;
}






