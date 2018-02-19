#include <math.h>

class vector_converter{
private:
  int ID = 0;
  double r3 = 1.7320508075;
  double Iu, Iv, Iw;
  double Ia, Ib, Id, Iq;
  double angle;

  void clark();
  void park();
  void inv_clark();
  void inv_park();
  void angle_set(double angle);
  void currents_set(double Iu, double Iv, double Iw);
  void currents_diff(double Id_diff, double Iq_diff);

public:
  void vector_converter(int ID){ this ->ID = ID; }
  int reID(){return ID;}
  void convert(double Iu, double Iv, double Iw, double angle){
    angle_set(angle);
    currents_set(Iu, Iv, Iw);
    clark();
    park();
  }
  void inv_convert(double Iq_diff, double Iq_diff){
    currents_diff(double Id_diff, double Iq_diff)
    inv_park();
    inv_clark();
  }
}

inline void vector_converter::clark()
{
  Ia = Iu;
  Ib = (r3 * Iu / 3) + (2 * r3 * Iv / 3);
}
inline void vector_converter::park()
{
  Id = cos(angle) * Ia + sin(angle) * Ib;
  Iq = -sin(angle) * Ia + cos(angle) * Ib;
}
 inline void vector_converter::inv_clark(){
   Iu = Ia;
   Iv = (-Ib + r3 * Ia) / 2;
   Iw =(-Ib + r3 * Ia) / 2;
 }
 inline void vector_converter::inv_park(){
   Ia = cos(angle) * Id + -sin(angle) * Iq;
   Ib = sin(angle) * Id + cos(angle) * Iq;
 }
 inline void vector_converter::angle_set(double angle){
   this ->angle = angle;
 }
 inline void vector_converter::currents_set(double Iu, double Iv, double Iw){
   this ->Iu = Iu;
   this ->Iv = Iv;
   this ->Iw = Iw;
 }
inline void vector_converter::currents_diff(double Id_diff, double Iq_diff){
  this ->Id  += Id_diff;
  this ->Iq += Iq_diff;
}
