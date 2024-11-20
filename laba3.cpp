//вариант 14 тарифы

#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ifstream fin;
  fin.open("data.txt");
  if (fin) {
    //==========объяевление структуры==============
    struct tarif {
      int id;
      char name[30];
      int price;
      int gig;
    };
    //============чтение из файла==================
    tarif* m1 = new tarif[4];
    for (int i = 0; i < 4; ++i){
      fin >> m1[i].id;
      fin >> m1[i].name;
      fin >> m1[i].price;
      fin >> m1[i].gig;
    }
    
    //===================вывод======================
    std::cout << "Существующие тарифы:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << m1[i].id << ") Тариф "
                  << m1[i].name << ": плата в месяц: "
                  << m1[i].price << " руб, доступно: "
                  << m1[i].gig << "Гб" << std::endl;
    }

    //================выбираем функцию====================
    int out;
    out << 1;
    while (out > 0){
    std::cout << "\nВыберите функцию: \n 1) средняя цена \n 2) среднее количество Гб \n 3) редактировать тариф \n 4) сохранить в новый файл \n 5) выход \n";
    int f;
    std::cin >> f;
    if (f == 1){
      std::cout << ((m1[0].price + m1[1].price + m1[2].price + m1[3].price)/4.0);
    }
    else if (f == 2){
      std::cout << ((m1[0].gig+m1[1].gig+m1[2].gig+m1[3].gig)/4.0);
    }
    else if (f == 3){
      
        //================редактируем====================
    std::cout << "Введите номер тарифа для изменения данных: \n";
    int a;
    int b;
    std::cin >> a;
    std::cout << "Какие данные изменить? \n";
    std::cout << "1) Название : "
     << m1[a-1].name << std::endl << "2) Плата: "
     << m1[a-1].price << std::endl << "3) Гб: "
     << m1[a-1].gig << "" << std::endl;
    std::cout << "Введите номер" << std::endl;
    std::cin >> b;
    if (b == 1){
        std::cout << "Введите другое название (желательно в кавычках)" << std::endl;
        std::cin >> m1[a-1].name;
    }
    else if (b == 2){
        std::cout << "Введите цену" << std::endl;
        std::cin >> m1[a-1].price;
    }
    else if (b == 3){
        std::cout << "Введите Гб" << std::endl;
        std::cin >> m1[a-1].gig;
    }
    std::cout << "Успешно изменено \n";
    b = 0;
    a = 0;

    }
    //=====================вывод=========================
    else if (f == 4){
      std::string filename;
      std::cout << "Введите название файла: ";
      std::cin >> filename;
      std::ofstream outf(filename);
      for (int i = 0; i < 4; ++i)
        outf << m1[i].id << "\n" << m1[i].name << "\n" << m1[i].price << "\n" << m1[i].gig << "\n";
      outf.close();
    }
    else if (f == 5){
      out == 0;
      return 0;
    }
    f == 0;
    }
    fin.close();
    delete[] m1;
    m1 = NULL;
  }
  else
  std::cout << "НЕТ ФАЙЛА НЕТУ ОТСУТСТВУЕТ";
  return 0;
}
