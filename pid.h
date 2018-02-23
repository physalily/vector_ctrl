class PID{
private:
  double kp;
  double ki;
  double kd;
  double p_diff;
  double i_diff;
  double d_diff;
  double prev_val;
public:
  PID(double kp, double ki, double kd){
    this -> kp = kp;
    this -> ki = ki;
    this -> kd = kd;
    d_diff = 0;
    prev_val = 0;
  }
  void update(double cte){
    p_diff = cte;
    i_diff += cte;
    d_diff = cte - prev_val;
    prev_cte = cte;
  }
  double re(){
    return kp *  p_diff + ki * i_diff + kd * d_diff;
  }
};
