#include <iostream>

int main() {

    double formue; // Kundens formue
    double renteSatsLav = 0.025; // 2.5% rente
    double renteSatsMid = 0.0375; // 3.75% rente
    double renteSatsMax = 0.05; // 5% rente

    
    std::cout << "Indtast din formue: ";
    std::cin >> formue;

if ( formue <= 100000) {
  double renteIndtaegt = formue * renteSatsLav;
  std::cout << "Din renteindtægt på et år vil være: " << renteIndtaegt << " kr.\n";
}
else if (formue < 250000) {
  double renteIndtaegt = formue * renteSatsMid;
  std::cout << "Din renteindtægt på et år vil være: " << renteIndtaegt << " kr.\n";
}
else if (formue >= 250000) {
  double renteIndtaegt = formue * renteSatsMax;
  std::cout << "Din renteindtægt på et år vil være: " << renteIndtaegt << " kr.\n";
}
}