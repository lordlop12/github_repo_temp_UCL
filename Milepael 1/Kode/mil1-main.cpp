
/* Main kode til milepæl 1 */


#include <iostream>
#include <string>

int main() {
    std::string navn;

    // Spørg brugeren om deres navn
    std::cout << "Hvad er dit navn? ";
    std::cin >> navn;

    // Udskriv en velkomstbesked
    std::cout << "Hej " << navn << "!" << std::endl;

    return 0;
}