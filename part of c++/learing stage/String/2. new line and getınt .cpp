  #include <iostream>
  #include <cstdlib> //for exit
  using namespace std;
  class DayOfYear
  {
    public:
        DayOfYear(int monthValue, int dayValue);
 //Initializes the month and day to arguments.
        DayOfYear(int monthValue);
 //Initializes the date to the first of the given month.
        DayOfYear( );
 //Initializes the date to January 1.
        void input( );
        void output( );
        int getMonthNumber( );
 //Returns 1 for January, 2 for February, etc.
        int getDay( );
    private:
    int month;
    int day;
    void testDate( );
};
 int main( )
 {
 DayOfYear date1(2, 21), date2(5), date3;
 cout << "Initialized dates:\n";
 date1.output( ); cout << endl;
 date2.output( ); cout << endl;
 date3.output( ); cout << endl;
 date1 = DayOfYear(10, 31);
 cout << "date1 reset to the following:\n";
 date1.output( ); cout << endl;
return 0;
 }

 DayOfYear::DayOfYear(int monthValue, int dayValue) : month(monthValue), day(dayValue)
 {
 testDate( );
 }
  DayOfYear::DayOfYear(int monthValue) : month(monthValue), day(1)
 {
 testDate( );
}
 DayOfYear::DayOfYear( ) : month(1), day(1)
 {/*Body intentionally empty.*/}
 //uses iostream and cstdlib:
 void DayOfYear::testDate( )
 {
 if ((month < 1) || (month > 12))
 {
    cout << "Illegal month value!\n";
    exit(1);
 }
if ((day < 1) || (day > 31))
 {
    cout << "Illegal day value!\n";
    exit(1);
 }
 }