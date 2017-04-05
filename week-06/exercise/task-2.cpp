#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

class BullsAndCows
{
private:
    int* numbersContainer;
    int sizeOfContainer;
    int numberOfGuesses;
public:
    BullsAndCows()
    {
        sizeOfContainer = 4;
        numbersContainer = new int[4];
        for(int i = 1; i <= 4; ++i){
        	numbersContainer[i-1] = i;
		}
        numberOfGuesses = 0;
    }
    BullsAndCows(int size)
    {
        if(size == 2 || size == 3 || size == 4)
        {
            sizeOfContainer = size;
        	numbersContainer = new int[size];
            numberOfGuesses = 0;
        }
        else {
			cout<<"Invalid value!"<<endl;
    		sizeOfContainer = 4;
       		numbersContainer = new int[4];
        	for(int i = 1; i <= 4; ++i){
        		numbersContainer[i-1] = i;
			}
        	numberOfGuesses = 0;
		}
	}
    BullsAndCows(int numbers[] , int size)
    {
    	bool isValid = true;
    	if(size == 2 || size == 3 || size == 4) {
        	numbersContainer = new int[size];
        	for(int i = 0 ; i < size;i++)
        	{
            	numbersContainer[i] = numbers[i];
        		for(int j = i+1; j < size; ++j){
        			if(numbers[i] == numbers[j]){
        				isValid = false;
					}	
				}
			}
        	sizeOfContainer = size;
        	numberOfGuesses = 0;
        	if(!isValid){
        		for(int i = 1; i <= size; ++i){
        			numbersContainer[i-1] = i;
				}	
			}
    	}
    	else {
    		sizeOfContainer = 4;
       		numbersContainer = new int[4];
        	for(int i = 1; i <= 4; ++i){
        		numbersContainer[i-1] = i;
			}
        	numberOfGuesses = 0;
		}
    }

    void SetContainerSize(int size)
    {
    	if(sizeOfContainer >= size)
        	sizeOfContainer = size;
        else{
        	int* temp;
        	temp = new int[sizeOfContainer];
        	for(int i = 0; i < sizeOfContainer; ++i){
        		temp[i] = numbersContainer[i];
			}
			delete []numbersContainer;
			numbersContainer = new int[size];
			for(int i = 0; i < size; ++i){
				numbersContainer[i] = temp[i];
			}
			for(int i = sizeOfContainer; i < size; ++i){
				srand(time(NULL));
				bool isValid = false;
				int full = sizeOfContainer;
				while(!isValid){
					isValid = true;
					int y = rand()%10;
					for(int j = 0; j < full; ++j){
						if(y == numbersContainer[j])
							isValid = false;
					}
				}
				full++;
			}
			sizeOfContainer = size;
			delete[] temp;
		}
    }
    void SetContainer(int* container)
    {
    	bool isValid = true;
    	for(int i = 0 ; i < size;i++){
        	for(int j = i+1; j < size; ++j){
        		if(container[i] == container[j]){
        			isValid = false;
				}	
			}
		}
        delete[] numbersContainer;
        if(container[0] == '0')
        {
            cout<<"The first number can't be 0 !"<<endl;
        }
        else if(!isValid){
        	cout<<"Wrong!!!!!1"<<endl;
		}
        else
        {
            numbersContainer = new int[sizeOfContainer];
            for(int i = 0; i < sizeOfContainer ; i++)
            {
                numbersContainer[i] = container[i];
            }
        }
    }

    bool IsInsideContainer(int number)const
    {
        for(int i = 0; i < sizeOfContainer ; i++)
        {
            if(number == numbersContainer[i])
            {
                return true;
            }
        }
        return false;
    }

    bool CowElement(int* arr, int position, int value)const
    {
        for(int i = sizeOfContainer-1 ; i >= 0 ; i--)
        {
            if(i != position)
            {
                if(arr[i] == value)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool BullElement(int* arr, int position, int value)const
    {
        if(arr[position-1] == value)
        {
            return true;
        }
        return false;
    }

    char* TryToGuess(int myGuess)
    {
        int cows = 0, bulls = 0;
        //char badguess[17];
        //char *guess = badguess;
        for(int i = sizeOfContainer-1;i >= 0;i--)
        {
            int guess = myGuess % 10;
            if(CowElement(numbersContainer,i,guess) == true)
            {
                cows++;
            }
            if(BullElement(numbersContainer,i,guess) == true)
            {
                bulls++;
            }
            myGuess = myGuess/10;
        }
        numberOfGuesses++;
        if(bulls == sizeOfContainer)
        {
            return "Congratulations! You made the right guess!";
        }
        else
        {
           cout<<"Cows:"<<cows<<"    Bulls:"<<bulls<<endl;
        }
    }

    void Start()
    {
        cout<<"                COWS AND BULLS"<<endl;
        cout<<"The numbers is with "<<sizeOfContainer<<" numbers."<<endl;
        int guess;
        cout<<"Make your guess:";
        cin>>guess;
        char *_myguess = TryToGuess(guess);
        while(strcmp(_myguess,"Congratulations! You made the right guess!") != 0)
        {
            cout<<"Make your guess:";
            cin>>guess;
            _myguess = TryToGuess(guess);
        }
        cout<<"Congratulations! You made the right guess!"<<endl;
        cout<<"You make "<<numberOfGuesses<<" guesses!"<<endl;
    }

    ~BullsAndCows()
    {
        delete[] numbersContainer;
    }
};

int main()
{
    int numbers[4] = {6 , 7 , 8 , 4};
    BullsAndCows number(numbers, 4);

    number.Start();

    return 0;
}
