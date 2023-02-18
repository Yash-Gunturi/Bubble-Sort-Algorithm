#include <iostream>
#include <cstring> // required for string manipulation
#include <iomanip> // required for tabular output
#include <string>

using namespace std; 

// PART 3/4: Sorting patient records

// Stating constants to later create temporary storage variables
const int ID_LENGTH = 8;
const int MAX_NAME_LENGTH = 10; 

// Creating a method that is called each time the list is given a sorting parameter
int swapAll(unsigned int* age, char id[][ID_LENGTH + 1], char firstName[][MAX_NAME_LENGTH], char lastName[][MAX_NAME_LENGTH], char* sex, int stor1, int stor2) {
   
    // Creating a variable that will act as a temporary storage spot 
    int tempAge;
    // Swapping 2 parts of the array ex. Fibonaci sequence code from class
    (tempAge = age[stor1]);
    (age[stor1] = age[stor2]);
    (age[stor2] = tempAge);

    // Repeating sorting code but for arrays instead of integers
    char temp1[ID_LENGTH + 1];
    strcpy(temp1, id[stor1]);
    strcpy(id[stor1], id[stor2]);
    strcpy(id[stor2], temp1);

    // Repeating sorting code 3 more times
    char temp2[MAX_NAME_LENGTH];
    strcpy(temp2, firstName[stor1]);
    strcpy(firstName[stor1], firstName[stor2]);
    strcpy(firstName[stor2], temp2);

    strcpy(temp2, lastName[stor1]);
    strcpy(lastName[stor1], lastName[stor2]);
    strcpy(lastName[stor2], temp2);

    char tempSex;
    (tempSex = sex[stor1]);
    (sex[stor1] = sex[stor2]);
    (sex[stor2] = tempSex);

    return 0;
}


int main(){

    // Provided arrays and constants
    const int NUM_PATIENTS = 10; // 10 patients will be included, this value cannot be modified
    const int MAX_NAME_LENGTH = 10; // no names longer than 10 characters, this value cannot be modified
    const int ID_LENGTH = 8;
    unsigned int age[NUM_PATIENTS] = {50, 22, 22, 89, 15, 16, 22, 32, 15, 66}; // 1D int array age of each patient
    char id[NUM_PATIENTS][ID_LENGTH + 1] = {"10854893", "10983922", "98333894", "57290888", "14899822", "79278282", "44293822", "62911023", "28399020", "33212322"}; // 1D int array identification #
    char firstName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"allison", "michael", "michael", "johnny", "sabrina", "helen", "ignacio", "melissa", "hassan", "melody"}; // 2D char array: first names for patients
    char lastName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"pratt","xiao", "barkley", "wu", "sappal", "mcdonald", "garza", "tran", "nahas", "baker"}; // 2D char array: last names for patients
    char sex[NUM_PATIENTS] = {'f','m','m','m','f','f','m','f','m','f'}; // 1D char array sex of the patient


    // PART 1: Select a primary sorting category from user input

    // Creating sorting category input variable and some integer a = 10 that is used for the for loops
    string input;
    int a = NUM_PATIENTS;
    
    // Asking the user for an input
    cout << "Please enter the sorting category (Age, ID, First, Last, Sex): " << endl;
    cin >> input;
    int n = input.length();

    char input_array[n + 1];
    while (true){
        
        // Creating a loop that will uppercase each individual character of the string input to make the code non-casesensitive
        for( int i=0 ; i < n; i++ ){ 
        input[i] = toupper( input[i] ) ;
        }
        // Copying the string to a character array so that strcmp can be used
        strcpy(input_array, input.c_str());

        // Creating a series of if statements for each sorting category that compares the input in caps with each sorting category
        if (!strcmp(input_array, "AGE")){
            cout << "Case 1: sorting by Age." << endl;
            // Creating a primary loop for the first round of sorting
            for (int i=0; i<a-1; i++){
                // Creating a secondary loop, this is useful because after the first sort
                // the largest value is already sorted so we have 1 less value
                for (int j=0; j<a-1-i; j++){
                    // Creating an if statement to sort names
                    if (age[j] > age[j+1]){
                        // Using the method written above sort everything according to age
                        swapAll(age, id, firstName, lastName, sex, j, j+1);
                    }

                    // Creating an if statement that is the secondary sorting category, first name
                    if (age[j] == age[j+1]){
                         if (strcmp(firstName[j], firstName[j+1]) > 0){
                            swapAll(age, id, firstName, lastName, sex, j, j+1);
                        }
                    }
                }
            }
        break;

        // Repeating sorting sequence for each categories
        }else if (!strcmp(input_array, "ID")){
            cout << "Case 2, sorting by ID" << endl;
            for (int i=0; i<a-1; i++){
                for (int j=0; j<a-1-i; j++){
                    if (strcmp(id[j], id[j+1]) > 0){
                        swapAll(age, id, firstName, lastName, sex, j, j+1);
                    } 
                }
            }
        break;

        }else if (!strcmp(input_array, "SEX")){
            cout << "Case 3, sorting by Sex" << endl;
            for (int i=0; i<a-1; i++){
                for (int j=0; j<a-1-i; j++){
                    if (sex[j] > sex[j+1]){
                        swapAll(age, id, firstName, lastName, sex, j, j+1);
                    }

                    if (sex[j] == sex[j+1]){
                         if (strcmp(firstName[j], firstName[j+1]) > 0){
                            swapAll(age, id, firstName, lastName, sex, j, j+1);
                        }
                    }
                }
            }
        break;

        }else if (!strcmp(input_array, "FIRST")){
            cout << "Case 4, Sorting by First Name" << endl;
            for (int i=0; i<a-1; i++){
                for (int j=0; j<a-1-i; j++){
                    if (strcmp(firstName[j], firstName[j+1]) > 0){
                        swapAll(age, id, firstName, lastName, sex, j, j+1);
                    }
                }
            }
        break;

        }else if (!strcmp(input_array, "LAST")){
            cout << "Case 5, sorting by Last Name" << endl;
            for (int i=0; i<a-1; i++){
                for (int j=0; j<a-1-i; j++){
                    if (strcmp(lastName[j], lastName[j+1]) > 0){
                        swapAll(age, id, firstName, lastName, sex, j, j+1);
                    }

                    if (lastName[j] == lastName[j+1]){
                         if (strcmp(firstName[j], firstName[j+1]) > 0){
                            swapAll(age, id, firstName, lastName, sex, j, j+1);
                        }
                    }
                }
            }
        break;

        // An error message if an unexpected input is given, then the code restarts
        }else {
            cin.clear();
            cout << "Unexpected input. Please input either Age, ID, First, Last, or Sex:" << endl;
            cin >> input;
        }
    }   
    
    // PART 2: Outputting patient records to terminal in tabular form

    // Display output
    cout << setw(11) << "Age:" << setw(10) << age[0] << setw(10) << age[1] << setw(10) << age[2] <<setw(10) << age[3] << setw(10) << age[4] << setw(10) << age[5] << setw(10) << age[6] << setw(10) << age[7] << setw(10) << age[8] << setw(10) << age[9] << endl;
    cout << setw(11) << "ID:" << setw(10) << id[0] << setw(10) << id[1] << setw(10) << id[2] <<setw(10) << id[3] << setw(10) << id[4] << setw(10) << id[5] << setw(10) << id[6] << setw(10) << id[7] << setw(10) << id[8] << setw(10) << id[9] << endl;
    cout << setw(10) << "First Name:" << setw(10) << firstName[0] << setw(10) << firstName[1] << setw(10) << firstName[2] <<setw(10) << firstName[3] << setw(10) << firstName[4] << setw(10) << firstName[5] << setw(10) << firstName[6] << setw(10) << firstName[7] << setw(10) << firstName[8] << setw(10) << firstName[9] <<endl;
    cout << setw(11) << "Last Name:" << setw(10) << lastName[0] << setw(10) << lastName[1] << setw(10) << lastName[2] <<setw(10) << lastName[3] << setw(10) << lastName[4] << setw(10) << lastName[5] << setw(10) << lastName[6] << setw(10) << lastName[7] << setw(10) << lastName[8] << setw(10) << lastName[9] <<endl;
    cout << setw(11) << "Sex:" << setw(10) << sex[0] << setw(10) << sex[1] << setw(10) << sex[2] <<setw(10) << sex[3] << setw(10) << sex[4] << setw(10) << sex[5] << setw(10) << sex[6] << setw(10) << sex[7] << setw(10) << sex[8] << setw(10) << sex[9] << endl;
    
    return 0;

}