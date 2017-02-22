#include <QTextStream>
#include <QDate>

int main(void) {
    
   QTextStream out(stdout);

   QDate dt(2015, 5, 11);  
   QDate nd = dt.addDays(55);
   
   QDate xmas(2015, 12, 24);
   
   out << "55 days from " << dt.toString() << " is " 
       << nd.toString() << endl;   
   out << "There are " << QDate::currentDate().daysTo(xmas) 
       << " days till Christmas" << endl;       
}