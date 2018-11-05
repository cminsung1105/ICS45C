#include <iostream>
#define MAXLEN 128

using namespace std;

class String{
    private:
        char buf[MAXLEN];
	bool inBounds(int i){
	    return i >= 0 && i < strlen(buf);
	}	

	static int strlen(const char * s){
	    int counter = 0;
	    for(int i = 0; s[i] != '\0' && i < MAXLEN-1 ; i++ ){
		++counter;
	    }
	    return counter;
	}
	
	static char * strcpy(char * dest, const char * src){
	    for (int i = 0; dest[i] != '\0'; i++)
		dest[i] = 0;
	     
	    int i;
	    for (i = 0; src[i] != '\0'; i++)
	        dest[i] = src[i];
	    dest[i] = '\0';
	    return dest;
	}

	static char * strcat(char * dest, const char * src){
	    int len = strlen(dest);
	    int i;
	    for (i = 0; src[i] != '\0'; i++){
		dest[i+len] = src[i];
	    }
	    dest[i+len] = '\0';
	    return dest;
	}

	static int strcmp(const char * left, const char * right){
	    for (int i = 0; left[i] != '\0'; i++){
		if (left[i] - right[i] != 0)
		    return left[i] - right[i];
	    }
	    return 0;
	}
	
	static int strncmp(const char *left, const char *right, int n){
	    int i;
	    for (i = 0; i < n; i++){
		if (left[i] - right[i] != 0)
		    return left[i] - right[i];
	    }
	    return 0;
	}

	static char * strchr(char * str, int c){
	    for (int i = 0; str[i] != '\0'; i++){
		if (str[i] == c)
		    return str + i;
	    }
	    return nullptr;
	}

	static char * strstr(char * haystack, char * needle){
	    int len = strlen(needle);
	    char * s = haystack;
	    char * p;
	    while (* s != '\0'){
		p = strchr(s, needle[0]);
		if (p == nullptr)
		    return nullptr;
		if (strncmp(p, needle, len) == 0)
		    return p;
		else
		    s = p  + 1;
	    }
	}	

	static const char * strstr(const char * haystack, const char * needle){
	    return const_cast<const char *>(strstr(const_cast<char *>(haystack),
		 const_cast<char *>(needle)));
	}

	static void reverse_cpy(char * dst, const char * src){
	    int len = strlen(src);
	    for (int i = len-1; i >= 0; --i)
		dst[len-i-1] = src[i];
	    dst[len] = '\0';
	}

    public:
        explicit String(const char * s = ""){
            if (strlen(s) > MAXLEN){
		cerr << "STRING OUT OF BOUNDS" << endl;
	    }
	    else {
 		int i;
                for (i = 0; s[i] != '\0' && i < MAXLEN-1; i++){
                    buf[i] = s[i];
                }
                buf[i] = '\0';
	    }
        }

	String(const String & s){
	    if (strlen(s.buf) > MAXLEN){
		cerr << "STRING OUT OF BOUNDS" << endl;
	    }
	    else {
		int i;
		for (i = 0; s.buf[i] != '\0' && i < MAXLEN-1; i++){
		    buf[i] = s.buf[i];
		}
		buf[i] = '\0';
	    }
	}

        String & operator = (const String & s){
	    strcpy(buf, s.buf);
            return *this;
        }

        char & operator [] (int index){
	    if (inBounds(index))
                return buf[index];
        }

	int size(){
	    return strlen(buf);
	}

	int indexOf(const char c){
	    const char * found = strchr(buf, c);
	    if (found == nullptr)
		return -1;
	    else
    	        return found - buf;
	}

	int indexOf(const String pattern){
	    const char * found = strstr(buf, pattern.buf);
	    if (found == nullptr)
		return -1;
	    else 
		return found - buf;
 	}    

	bool operator == (const String s){
	    return strcmp(buf, s.buf) == 0;
	}

	bool operator != (const String s){
	    return strcmp(buf, s.buf) != 0;
	}

	bool operator > (const String s){
	    return strcmp(buf, s.buf) > 0;
	}	

	bool operator < (const String s){
	    return strcmp(buf, s.buf) < 0;
	}

	bool operator <= (const String s){
	    return strcmp(buf, s.buf) <= 0;
	}

	bool operator >= (const String s){
	    return strcmp(buf, s.buf) >= 0;
	}

	String reverse(){
	    String rev;
	    reverse_cpy(rev.buf, buf);
	    return rev;    
	}

	String operator + (const String s){
	    strcat(buf, s.buf);
	    if (strlen(buf) > 128)
		cerr << "STRING OUT OF BOUNDS" << endl;
	    else 
	        return *this;
	}

	String operator += (const String s){
	    strcat(buf, s.buf);
	    if (strlen(buf) > 128)
		cerr << "STRING OUT OF BOUNDS" << endl;
	    else
	        return *this;
	}

        void print(ostream & out){
            out << buf;
        }

        void read(istream & in){
            in.getline(buf, MAXLEN); 
        }
};

ostream & operator << (ostream & out, String str){
    str.print(out);
    return out;
}

istream & operator >> (istream & in, String & str){
    str.read(in);
    return in;
}

