// Made by Maksim Bronnikov
#include <iostream>
#include <numeric>

using namespace std;

// introduce abstraction in order to move figure read logic from main algo
// because type of figure not interested, only centers!
struct figure{
    void center(int &x, int &y) const{
        x = _x;
        y = _y;
    }

    int _x = 0;
    int _y = 0;
};

struct circle : figure{
    
};

struct rectangle : figure{

};

istream& operator>>(istream& is, rectangle& fig)
{
    int x0, y0;
    int x1, y1;
    int x2, y2;
    int x3, y3;

    is >> x0 >> y0;
    is >> x1 >> y1;
    is >> x2 >> y2;
    is >> x3 >> y3;

    // scale by 2 garants integer centers
    x0 <<= 1; y0 <<= 1;
    x2 <<= 1; y2 <<= 1;

    // center - mid of diag
    fig._x = (x0 + x2) >> 1;
    fig._y = (y0 + y2) >> 1;

    return is;
}

istream& operator>>(istream& is, circle& fig)
{
    int r, x0, y0;

    is >> r >> x0 >> y0;

    // center is given (scale by 2 because recatangles are scaled too)
    fig._x = x0 << 1;
    fig._y = y0 << 1;

    return is;
}

void read_figure(istream& is, int& x, int& y){
    int type;
    is >> type;

    if(type){
        rectangle fig;
        cin >> fig;
        fig.center(x, y);
    }else{
        circle fig;
        cin >> fig;
        fig.center(x, y);
    }
}

int normalize(int& dx, int& dy){
    int k = gcd(dx, dy);

    if(k == 0)
        return k;

    if(dx < 0)
        k *= -1;

    dx /= k;
    dy /= k;

    return k;
}



int main(){
    int n;
    cin >> n;

    // Two(one) figures => eazy line
    if(n < 3){
        cout << "Yes" << endl;
        return 0;
    }


    int dx, dy; // k = dy/dx - angle coefficient definition
    bool second_defined = false;
    
    // define first center
    int x0, y0;
    read_figure(cin, x0, y0);

    // main idea: center of all figures must be on single line 
    while(--n){
        // define next center
        int x1, y1;
        read_figure(cin, x1, y1);

        if(second_defined){
            int kx = x1 - x0;
            int ky = y1 - y0;
            // if kx = ky = 0 => same point => same line
            // if kx = dx and ky = dy => same line
            // otherwise bad news
            if(normalize(kx, ky) && (kx != dx || ky != dy)){
                cout << "No" << endl;
                return 0;
            }
        }else{
            // define second center if possible
            dx = x1 - x0; 
            dy = y1 - y0;
            // if dx = dy = 0 => x1=x0, y1=y0 => same point
            // otherwise second coord and unique line defined
            if(normalize(dx, dy))
                second_defined = true;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
