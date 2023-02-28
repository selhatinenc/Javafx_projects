public class elves extends hero implements Rough,Mage {

    elves(hero o,String heroname,String oppname) {
        opphero=o;
        this.heroname=heroname;
        this.oppname=oppname;
        herotype = "elves";
       
        createabb();
    
    } 
    @Override public void setopp(hero x){
        opphero=x; createabb();
    }
  
    @Override
    public void setother() {
       
        super.setother();
        mp = hp - 10;
        cmp = mp;
        speed = lvl + 4;
        
    }
    @Override 
    public void updatelvl(int x){
        super.updatelvl(x);
        mp = hp - 10;
        speed = lvl + 4;
    }
    @Override
    public void shotarrow(hero h, hero opphero) {
        // TODO Auto-generated method stub
        
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

 
}