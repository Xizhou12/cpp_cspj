#include <bits/stdc++.h>
using namespace std;

int main(){
  string s = "They say he carved it himself...from a BIGGER spoon";
  string s2 = "find your soul-mate, Homer.";
  s.replace( 32, s2.length(), s2 );
  cout << s << endl;

  string str1( "Alpha Beta Gamma Delta" );
  unsigned int loc = str1.find( "Omega", 0 );
  if( loc != string::npos )
    cout << "Found Omega at " << loc << endl;
  else
    cout << "Didn't find Omega" << endl;
}