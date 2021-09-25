// Made by Maksim Bronnikov
#ifndef _FFT_
#define _FFT_

namespace custom{

std::vector<custom::complex> fft(const std::vector<custom::complex> &x, bool inverse = false);
void inplace_fft(std::vector<custom::complex> &x, bool inverse = false);

}


#endif // _FFT_