import java.util.Random;
import java.util.Scanner;


public class hero {
    protected int lvl, hp, mp, speed, attack, magic, chp, cmp;// chp=current hp, cmp==current mp
    public hero opphero;
    protected String herotype;
    protected boolean turn = false;
    protected boolean quickattack = false;
    protected String heroname;
    protected String oppname;
    protected abilities abb;
    Random rand;
    Scanner sc;

    hero() {
        rand=new Random();
    }

    public void setsc(Scanner scan){
        sc=scan;
    }
    public void createabb() {
        abb = new abilities(this, opphero, heroname, oppname, sc);
    }

    hero(hero o, String heroname, String oppname) {
        opphero = o;
        this.heroname = heroname;
        this.oppname = oppname;

        setlvl(1);

    }
    hero(hero o, String heroname, String oppname,boolean x) {
        opphero = o;
        this.heroname = heroname;
        this.oppname = oppname;

        setlvl(1);

    }
    public void characterchange(int bcmp,int bchp){
        chp=bchp; cmp=bcmp; 
        controlchp(); controlcmp();
    }

    public void setheroname(String hero, String opphero) {
        heroname = hero + "(" + herotype + ")";
        oppname = opphero + "(" + herotype + ")";
    }

    public void chooseturn() {
        if (quickattack == true && opphero.getquickattack() == false) {
            turn = true;
            opphero.setturn(false);

        } else if (quickattack == false && opphero.getquickattack() == true) {
            opphero.setturn(true);
            turn = false;

        } else if (speed >= opphero.getspeed()) {
            turn = true;
            opphero.setquickattack(false);
        }

        else {
            opphero.setturn(true);
            turn = false;
        }
        quickattack = false;
        opphero.setquickattack(false);

    }

    // constructor
    public void setopp(hero x) {

    }

    // getters
    public String getheroname(){
        return heroname;
    }
    public boolean getturn() {
        return turn;
    }

    public int getlvl() {
        return lvl;
    }

    public int gethp() {
        return hp;
    }

    public int getmp() {
        return mp;
    }

    public int getspeed() {
        return speed;
    }

    public int getattack() {
        System.out.println(heroname+" attacking --- attack ability: "+attack);
        return attack;
    }

    public int getmagic() {
        return magic;
    }

    public int getchp() {
        return chp;
    }

    public String getherotpye() {
        return herotype;
    }

    public int getcmp() {
        return cmp;
    }

    public boolean getquickattack() {
        return quickattack;
    }

    // setters
    public void setlvl(int l) {

        this.lvl = l;
        setother();
    }

    public void setopplvl(int x) {
        
       int r=rand.nextInt(1);
        lvl=(r==1)?x:x-1;
        setother();
    }

    public void win() {
        lvl++;
        hp = 20 + 4 * lvl;
        mp = hp / 2;
        chp += (hp * 10) / 100;
        cmp += (mp * 10) / 100;
        speed = lvl;
        attack = (hp / 10) + 1;
        magic = (mp / 5) + 2;
    }

    public void setcmp(int xmp) {
        if (cmp + xmp >= 0)
            cmp += xmp;
            controlcmp();

    }

    public void setchp(int xhp) {
        
      
        this.chp = xhp;
        if(chp<0) chp=0;
        controlchp();

    }
    public void controlchp(){
        if(chp>hp)chp=hp;
        else if(chp<0) chp=0;
    }
    public void controlcmp(){
        if(cmp>mp)cmp=mp;
        else if(cmp<0) cmp=0;
    }

    public void setturn(boolean t) {
        turn = t;
    }

    public void setquickattack(boolean x) {
        quickattack = x;

    }

    // methods

    public void setother() {
        hp = 20 + 4 * lvl;
        chp = hp;
        mp = hp / 2;
        cmp = mp;
        speed = lvl;
        attack = (hp / 10) + 1;
        magic = (mp / 5) + 2;

    }

    public void updatelvl(int x) {
        this.lvl = x;
        hp = 20 + 4 * lvl;

        mp = hp / 2;

        speed = lvl;
        attack = (hp / 10) + 1;
        magic = (mp / 5) + 2;
    }

    public int seedamage(int d) {
        int tempchp = chp;
        chp -= d;
        defend();
        if (chp > 0)
            backattack();/// freee!!!!!!!!!
        if (chp < 1)
            System.out.println(heroname + " damaged " + chp + " and as a result died ");
        else if (chp > 0)
            System.out.println(heroname + " damaged " + (tempchp-chp));
        controlchp();
        return chp < 1 ? 0 : 1;
    }

    public boolean controldamage(int d) {// if hero die this return false
        int tempchp = chp;
        chp -= d;
       contdefend();
        if (chp < 1) {
            chp = tempchp;
            return false;
        }
        chp = tempchp;
        return true;
    }

    private void defend() {
        System.out.println(heroname+" defends attack and gain "+((10*hp)/100)+" hp");
        chp += (10 * hp) / 100;

    }
    private void contdefend() {
        chp += (10 * hp) / 100;

    }

    public void backattack() {

    }

    public int controlgame() {
        if (chp < 1)
            return 0;
        return 1;
    }

    public boolean isAllive() {
        if (chp < 1)
            return false;
        return true;
    }

    public void randomstart(boolean x) {
      
        try {
            abb.randomstart(x);
        } catch (Exception e) {
            
        }

    }

    public void herostate() throws InterruptedException {

        System.out.println(heroname + "'s current hp:" + chp + " current mp: " + cmp + " current lvl: " + lvl);
        Thread.sleep(2000);
    }
    public void showAll() throws InterruptedException{
        System.out.println("----------------------------------------------------------------------------");
        System.out.println(heroname+"'s hp:"+hp+" mp:"+mp+" lvl:"+lvl+" speed:"+speed+" magic: "+magic);
        System.out.println("----------------------------------------------------------------------------");

        Thread.sleep(5000);
    }

    void dothis(int x) {
        System.out.println(x);

    }

}
