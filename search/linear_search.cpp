
// Headers - only the standard c++ library is needed
#include "iostream"
#include "stdlib.h"
#include "vector"
#include "stdexcept"
#include "cstdlib"

void LinearSearch(int target, std::vector<int> array)
{

    bool is_target_found = false;

    /* Search for the element */
    for (unsigned int i = 0; i<array.size(); ++i) // this loops cycles every position in the vector
    {
        if (array[i] == target) // Condition to satisfy
        { 
            // The code below is executed only when the element is found
            std::cout << "Element found at postion " << i << "!" << std::endl;
            is_target_found = true;
        }
    } 

    /* Stop method */
    if (is_target_found == false)
    {    
        std::cout << "The searched element (" << target << ") is not present in the array!" << std::endl;
        throw std::runtime_error("Error detected! It's important to stop the program if the searched element is mandatory further along the road!");
    }        
}

int main()
{
    /* Request user input for vector size*/
    int n_elements;
    std::cout << "Please insert the number of elements and press enter..." << std::endl;
    std::cin >> n_elements;
    std::cout << std::endl;
    std::vector<int> user_defined_array(n_elements);

    /* Request values to fill the vector */
    for (int i = 0; i<user_defined_array.size(); ++i)
    {
        std::cout << "Insert element in position " << i << " and press enter:" << std::endl;
        std::cin >> user_defined_array[i];
        std::cout << std::endl;
    }

    /* Request value to be searched */
    int target_value;
    std::cout << "Plese insert the element you are looking for and press enter..." << std::endl;
    std::cin >> target_value;
    std::cout << std::endl;

    /* Call LinearSearch algorithm */
    try 
    {
        LinearSearch(target_value, user_defined_array);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }    

    return EXIT_SUCCESS;

}
