public class halflings extends hero implements Fighter, Rough {

    halflings(hero o, String heroname, String oppname) {
        herotype = "halflings";
        opphero = o;
        this.heroname = heroname;
        this.oppname = oppname;
       
    } @Override
    public void setother() {
       
        super.setother();
     
        
    }
    @Override public void setopp(hero x){
        opphero=x; createabb();
    }

    public void restorehp() {
        if (cmp > 6) {
            chp += 20;
            cmp -= 7;
        }
    }
    @Override 
    public void updatelvl(int x){
        super.updatelvl(x);
        
    }

    public void restoremp() {
        if (hp > 1) {
            chp -= 2;
            cmp += 2 * lvl;
        }
    }

    @Override
    public void backattack() {
        if (opphero.getchp() > 9)
            opphero.seedamage(10);

    }
    @Override
    public void quicattack(hero h) {
        // TODO Auto-generated method stub
        
    }
    @Override
    public void shotarrow(hero h, hero opphero) {
        // TODO Auto-generated method stub
        
    }
    @Override
    public void slash(hero h, hero opp) {
        // TODO Auto-generated method stub
        
    }
    @Override
    public void burst(hero h, hero opp) {
        // TODO Auto-generated method stub
        
    }

}
