#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc<3) return 0;
	string* str = new string[3] { argv[1], argv[2], argv[3]};
	string s = "";

	size_t found1 = string::npos,
	found2 = string::npos;


	while (str[0].find(str[1]) != string::npos && 
			   str[0].find(str[2]) != string::npos)
	{
		found1 = str[0].find(str[1]);
		if (found1 != string::npos)
		{
			int leftPos = found1+str[1].length();
			s = str[0].substr(leftPos, str[0].length()); 
		
			found2 = s.find(str[2]);
			if (found2 != string::npos && (found2+leftPos)>found1)
			{
				found2 += leftPos;
				cout << "'" << str[0].substr(leftPos,found2-(found1+str[1].length())) << "'\n";
				str[0] = str[0].substr(found2+str[2].length(),str[0].length());
			}
		}
	}
	return 0;
}
