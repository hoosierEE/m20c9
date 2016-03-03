#ifndef CAPSWITCH_H
#define CAPSWITCH_H

class CapSwitch {
public:
CapSwitch(uint8_t _pin) : pin(_pin),THRESH(200) {}
    ~CapSwitch() {}

    void update(void)
    {
        int val = touchRead(pin);
        static int idx{0};
        buf[++idx%BUF_LEN] = val;
        if (accept) {
            accept = false;
            double avg = get_avg();
            cs = avg-val>THRESH||val-avg<=THRESH;
            fall = ps && !cs;
            rise = cs && !ps;
        }
    }

    bool pressed(void) {return reset_edge(fall);}
    bool released(void) {return reset_edge(rise);}

private:
    bool reset_edge(bool &edge)
    {
        bool t = edge;
        edge = false;
        accept = true;
        return t;
    }

    double get_avg(void)
    {
        double sum{0};
        for (uint8_t i=0;i<BUF_LEN;++i) {sum+=buf[i];}
        return sum/BUF_LEN;
    }

    uint8_t pin;
    const int THRESH;
    static const uint8_t BUF_LEN{7};
    int buf[BUF_LEN]{0};
    bool cs,ps,fall,rise;
    bool accept{true};
};

#endif // CAPSWITCH_H
