                //RSA Encryption and Decryption
                //The RSA Algorithm goes through 3 main stages//


    //1-first - Key Generation//
    //choose two primes P,Q
    //compute n=p*q
    //compute euler φ =(p-1)*(q-1)
    //choose e,1<e<φ  and must be coprime with φ  (7)
    //so public key is (n,e)
    //and the private key is (d,p,q)
    //-------------------------------------------------------

    //2-second - Message Encryption//
    //C=m^e mod n 
    //------------------------------------------------------

    //3-third - Message Decryption// 
    //D=e^-1 mod φ  
    //M=c^d mod n 
    //--------------------------------------------------------
    
    //Now let's code 

    #include<iostream>
    #include<math.h>
    using namespace std;
    
    //gcd(Greatest common divisor)
    int gcd(int a, int b) {
    int t;
    while(1) {
        t= a%b;
        if(t==0)
        return b;
        a = b;
        b= t;
    
    }
    }

    int main() {
    //2 random prime numbers
    double p = 13;
    double q = 11;
    double n=p*q;//calculate n
    double track;
    double φ= (p-1)*(q-1);//calculate φ
    double e=7  ;

    // for checking that 1 < e < φ and gcd(e, φ) = 1  | e and φ are coprime.
    while(e<φ) {
        track = gcd(e,φ);
        if(track==1)
            break;
        else
            e++;
    }

    //private key
    //d stands for decrypt
    //choosing d such that it satisfies d*e = 1 mod φ
    double d1=1/e;
    double d=fmod(d1,φ);
    double message = 54;
    double c = pow(message,e); //encrypt the message
    double m = pow(c,d);//decrypt the message
    c=fmod(c,n);
    m=fmod(m,n);



    cout<<"Original Message = "<<message<<"\n";
    cout<<""<<"p = "<<p<<"\n";
    cout<<""<<"q = "<<q<<"\n";
    cout<<""<<"n = pq = "<<n<<"\n";
    cout<<""<<"φ = "<<φ<<"\n";
    cout<<""<<"e = "<<e<<"\n";
    cout<<""<<"d = "<<d<<"\n";
    cout<<""<<"Encrypted message = "<<c<<"\n";
    cout<<""<<"Decrypted message = "<<m<<"\n";
    
    return 0;
    }