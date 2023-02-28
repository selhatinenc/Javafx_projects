
class human extends hero implements Fighter, Rough, Mage{
   
    human(hero o,String heroname,String oppname){
        opphero=o;
        this.heroname=heroname;
        this.oppname=oppname;
        
        herotype = "human";
        createabb();

    }
    human(hero o,String heroname,String oppname,boolean x){
        opphero=o;
        this.heroname=heroname;
        this.oppname=oppname;
        
        herotype = "human";
        createabb();

    }
     @Override
    public void setother() {
       
        super.setother();
        hp = 35 + (3 * lvl);
        
            chp = hp;
    
    }  @Override public void setopp(hero x){
        opphero=x; createabb();
    }
    @Override 
    public void updatelvl(int x){
        super.updatelvl(x);

        hp = 35 + (3 * lvl);
        
    }
    @Override
    public void fire(hero h, hero opphero) {
        // TODO Auto-generated method stub
        
    }
    @Override
    public void thunder(hero h, hero opphero) {
        // TODO Auto-generated method stub
        
    }
    @Override
    public void blizzard(hero h, hero opphero) {
        // TODO Auto-generated method stub
        
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