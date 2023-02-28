public class dwarfs extends hero implements Fighter,Mage {

    dwarfs(hero o,String heroname,String oppname) {
        opphero=o;
        this.heroname=heroname;
        this.oppname=oppname;
        herotype = "dwarfs";
  
        createabb();

    } @Override
    public void setother() {
       
        super.setother();
        hp = 40 + lvl;
        chp = hp;
        mp = 10 + lvl;
        cmp = mp;
        speed = (lvl / 2) + 1;
        
    }  @Override public void setopp(hero x){
        opphero=x; createabb();
    }
    @Override 
    public void updatelvl(int x){
        super.updatelvl(x);
        hp = 40 + lvl;
       
        mp = 10 + lvl;
       
        speed = (lvl / 2) + 1;
        
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
    public void slash(hero h, hero opp) {
        // TODO Auto-generated method stub
        
    }
    @Override
    public void burst(hero h, hero opp) {
        // TODO Auto-generated method stub
        
    }

   

}
