#include <iostream>
#include <fstream>
#include <complex>

using namespace std;

static const int width = 600;
static const int height = 600; 

int value (double x, double y)  {
    complex<double> point(x, y);
    complex<double> z(0.0, 0.0);
    int nb_iter = 0;
    while (abs(z) < 2 && nb_iter <= 20) {
        z = z * z + point;
        nb_iter++;
    }
    if (nb_iter < 20)
        return (255 * nb_iter) / 20;
    else 
        return 0;
}

int main () {
    ofstream my_Image("mandelbrot.ppm");

    if (my_Image.is_open()) {
        my_Image << "P3\n" << width << " " << height << " 255\n";
        for (int j = 0; j < height; j++)  {
            for (int i = 0; i < width; i++) {
                double x = (double)i / width * 2.0 - 0.75;
                double y = (double)j / height * 2.0 - 1.0;
                int val = value(x, y);
                my_Image << val << ' ' << 0 << ' ' << 0 << "\n";
            }
        }
        my_Image.close();
    }
    else
        cout << "Could not open the file";
    
    return 0;
}
