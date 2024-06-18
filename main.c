#include <stdio.h>
#include "neural_network.h" 

int trainNetwork(double numberOfTrainings)
{
    int i = 1;
    frontPropagation();
    printf("\033[0;33m%lf \033[0;37mand \033[0;33m%lf \033[0;37m-> \033[1;34m%lf\033[0;37m\n",inputLayer[0],inputLayer[1],outputLayer[0]);
    //While cost result is too high it will compute front propagations
    while (i < numberOfTrainings)
    {
        //Initializes randomly intput layer values with 0 and 1
        double firstNeuron = randomnumber();
        double secondNeuron = randomnumber();
        if(firstNeuron >= 0.5)
            inputLayer[0] = 1;
        else 
            inputLayer[0] = 0;

        if(secondNeuron >= 0.5)
            inputLayer[1] = 1;
        else 
            inputLayer[1] = 0;
        expectedLayer[0] = (int)inputLayer[0]^(int)inputLayer[1];


        printf("\033[0;33m%lf\033[0;37m and \033[0;33m%lf \033[0;37m-> \033[1;34m%lf\033[0;37m\n",inputLayer[0],inputLayer[1],outputLayer[0]);

        //Applies front propagation 
        frontPropagation();

        //Applies the gradient
        applyGradientToLayer();
        
        i++;
    }
    printf("\n");
    return i;
}

int main()
{
    srand(time(NULL));


    //Assign random bias to the hidden layer and the output layer
    assignRandomToVector(hiddenBias, numHidden);
    assignRandomToVector(outputBias, numOutput);


    //Assign weights (input to hidden)
    assignRandomToMatrix(numHidden, numInput, inputToHidden);


    //Assign weights (hidden to output)
    assignRandomToMatrix(numOutput, numHidden, hiddenToOutput);
     
    printf("\e[1;1H\e[2J");
    
    for(int i=0; i<numHidden;i++)
    {
        for(int j=0; j<numInput;j++)
            printf("%lf\n",inputToHidden[numHidden][numInput]);
    }

    int quit = 0;
    while (quit == 0)
    {        
        printf("\n\033[0;33mYou're on the display page of the neural network that computes the XOR function values. What do you want to do ? :\033[0;37m\n\n\n\033[1;32m-1\033[0;37m : Train the XOR Neural Network\n\n\033[1;32m-2 \033[0;37m: Compute a value of your choice of the XOR function\n\n\033[1;32m-3 \033[0;37m: Quit the program\033[0;36m\n\n");
        long int *a = malloc(sizeof(long int));
        scanf("%ld",a);
        printf("\n");
        while(*a != 1 && *a != 2 && *a !=3 && quit==0)
        {
            printf("\033[1;31mPlease type a valid value (characters are not avaialable) :\033[0;35m \n");
        }

        //TRAINS THE NETWORK
        if(*a == 1)
        {

            printf("\e[1;1H\e[2J");
            printf("\n\033[0;33mYou're about to train a neural network that computes the XOR function values.\nHow many times do you want to train the XOR Neural Network :\n \n");

            long int *m = malloc(sizeof(long int));
            printf("\033[0;37mNumber of trainings wanted : \033[0;36m");
            scanf("%ld",m);
            printf("\033[0;37m \n\n");
            while (*m % *m != 0)
            {
                printf("\033[1;31mPlease type a valid value (characters are not available) :\033[0;35m \nNumber of trainings wanted : \033[0;36m");
                scanf("%ld",m);
                printf("\033[0;37m \n\n");
            }
            trainNetwork(*m); 
            system("clear");
            printf("You just trained the neural network : \033[0;36m%d \033[0;37mtimes\n\n", trainNetwork(*m));
            printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

        }
        
        //COMPUTES SPECIFIC VALUES
        if(*a == 2)
        {
            printf("\e[1;1H\e[2J");
            long int *b = malloc(sizeof(long int));
            long int *c = malloc(sizeof(long int));
            printf("\n\033[0;33mYou're about to compute a value of the Neural Network. \n\033[0;37m(N.B.: If the Network have not been trained yet or not enough the output value may not be precise enough)\n\n");
            printf("\n\033[0;33mWhat first input value do you want ?:\033[0;36m \n\n");
            scanf("%ld",b);
            printf("\033[0;33m\nWhat second input value do you want ?:\033[0;36m\n\n");
            scanf("%ld",c);
            printf("\033[0;37m\n");
            printf("\e[1;1H\e[2J");
            inputLayer[0] = *b , inputLayer[1] = *c;
            expectedLayer[0] =(int)*b^(int)*c;
            frontPropagation();
            printf("Your previous test result is :\n\n\033[0;33m%lf \033[0;37mand \033[0;33m%lf \033[0;37m-> \033[1;34m%lf\033[0;37m\n",inputLayer[0],inputLayer[1],outputLayer[0]);

        }
    
        if(*a == 3)
        {
            printf("\033[0;33mProgram just ended.\033[0;37m\n\n");
            quit = 1;
        }
    }


    return 0;
}

