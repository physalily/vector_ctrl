#ifndef GUARD_
#define GUARD_
#include <math.h>
#endif

class vector_converter{
private:
  int ID = 0;
  double r3 = sqrt(3);
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
  vector_converter(){}
  vector_converter(int ID){ this -> ID = ID; }
  int reID(){return ID;}

  //park, clark converts
  void convert(double Iu, double Iv, double Iw, double angle){
    angle_set(angle);
    currents_set(Iu, Iv, Iw);
    clark();
    park();
  }
  //inverse park, clark converts
  void inv_convert(double Id_diff, double Iq_diff){
    currents_diff(double Id_diff, double Iq_diff)
    inv_park();
    inv_clark();
  }
  //outputs
  double out_u(){return this -> Iu;}
  double out_v(){return this -> Iv;}
  double out_w(){return this -> Iw;}
}

//converters contents
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

 //set fanctions contents
 inline void vector_converter::angle_set(double angle){//arg is radian
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
