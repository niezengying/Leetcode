/* 65. Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
*/

//Hard
#define numInput 6
#define numStateType 10

 typedef enum{	//INTPUT
	 DIGIT, SIGN, DOT, EXP, OTHERCH, END
 }Input;

typedef enum{      //DFA 10 States
	START, INDIGIT, INSIGN, INDOT0, INDOT1,
	INE, INES, AFE, NOTNUM,ISNUM
}StateType;

static const int Accept[numStateType]={0,0,0,0,0,0,0,0,1,2};  //Accept States

static const int TransitionTable[numStateType-2][numInput] = {  //Transition Table
	{ 1, 2, 3, 9, 9, 9 },
	{ 1, 9, 4, 5, 9, 8 },
	{ 1, 9, 3, 9, 9, 9 },
	{ 4, 9, 9, 9, 9, 9 },
	{ 4, 9, 9, 5, 9, 8 },
	{ 7, 6, 9, 9, 9, 9 },
	{ 7, 9, 9, 9, 9, 9 },
	{ 7, 9, 9, 9, 9, 8 }
};

class Solution {
public:
	Input IndexOfInput(char ch)
	{	//classify the ch
		if(ch>='0' && ch<='9') return DIGIT;
	
		switch(ch){
		case '+':
		case '-':
			return SIGN;
			break;

		case '.':
			return DOT;
			break;

		case 'E':
		case 'e':
			return EXP;
			break;

		default:
			return OTHERCH;
			break;
		}
	}

    bool isNumber(string s) {
		int len;
		bool result = false;
		StateType currentState = START, newState;
		
		for(auto it = s.rbegin(); it!=s.rend(); it++)
		{
			if(*it!=' ')		break;
			s.pop_back();
		}

		if(s.empty()) return false;

		for(auto it = s.begin();it!=s.end();) 
		{
			if(*it!=' ')		break;
			s.erase(s.begin());
		}
		if(s.empty()) return false;

		len = s.size();
		s.push_back('\0');

		for(int i=0;i<=len;i++ )
		{
			int ch;
			if(i == len)	ch = END;
			else  ch = IndexOfInput(s[i]);

			newState =(StateType)TransitionTable[currentState][ch];

			if(Accept[newState] == 1)
				return true;
			else if(Accept[newState] == 2)
				return false;
		
			currentState = newState;
		}
	}
};
