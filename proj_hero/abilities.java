import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;
import java.util.Scanner;

public class abilities {
    hero h;
    hero opp;
    Scanner scanner;
    String heroname;
    String oppname;
    HashMap<String, Boolean> map;
    Random random;
    ArrayList<String> cont;
    String[] humanarr, dwarfsarr, elvesarr, halfingsarr;
    ArrayList<String> contarr;

    abilities(hero h, hero oppose, String hname, String oppname, Scanner sc) {
        String[] humanarr = { "slash", "burst", "shotarrow", "fire", "thunder", "blizzard",
                "struggle" };

        String[] dwarfsarr = { "slash", "burst", "shotarrow", "fire", "thunder", "blizzard",
                "restorehp" };
        String[] elvesarr = { "slash", "burst", "shotarrow", "fire", "thunder", "blizzard",

                "restoremp" };
        String[] halflingsarr = { "slash", "burst", "shotarrow", "fire", "thunder", "blizzard",
                "struggle", "restorehp", "restoremp", "secbreak", "mimic" };
        this.humanarr = humanarr;
        this.dwarfsarr = dwarfsarr;
        this.elvesarr = elvesarr;
        this.halfingsarr = halflingsarr;

        cont = new ArrayList<>();
        this.oppname = oppname;
        heroname = hname;
        random = new Random();

        scanner = sc;
        this.h = h;
        opp = oppose;

    }

    public int backattack(boolean x) {
        int estdamage = h.gethp() / 4;

        if (h.getchp() > 10) {

            if (x == true)
                return 1;
            h.setchp(h.getchp() - 10);
            System.out.println(heroname + " uses back attack at the cost of 10 hp ");
            opp.seedamage(estdamage);
        }
        return 0;

    }

    public void randomstart(boolean y) throws InterruptedException {
        h.setturn(false);
        opp.setturn(true);
        contarr = new ArrayList<>();
        map = new HashMap<>();

        String contString = "";

        int x;

        x = slash(true);
        if (x == 1)
            map.put("slash", true);
        else
            map.put("slash", false);

        x = burst(true);
        if (x == 1)
            map.put("burst", true);
        else
            map.put("burst", false);

        x = quicattack(true);
        if (x == 1)
            map.put("quickattack", true);
        else
            map.put("quickattack", false);

        x = shotarrow(true);
        if (x == 1)
            map.put("shotarrow", true);
        else
            map.put("shotarrow", false);

        x = fire(true);
        if (x == 1)
            map.put("fire", true);
        else
            map.put("fire", false);

        x = thunder(true);
        if (x == 1)
            map.put("thunder", true);
        else
            map.put("thunder", false);

        x = blizzard(true);
        if (x == 1)
            map.put("blizzard", true);
        else
            map.put("blizzard", false);

        x = backattack(true);
        if (x == 1)
            map.put("backattack", true);
        else
            map.put("backattack", false);

        x = restorehp(true);
        if (x == 1)
            map.put("restorehp", true);
        else
            map.put("restorehp", false);

        x = restoremp(true);
        if (x == 1)
            map.put("restoremp", true);
        else
            map.put("restoremp", false);

        map.put("secbreak", true);

        x = mimic(true);
        if (x == 1)
            map.put("mimic", true);
        else
            map.put("mimic", false);

        Thread.sleep(3000);
        String htpye = h.getherotpye();
        if (htpye.equals("human"))
            printchooses(humanarr, contString);
        else if (htpye.equals("elves"))
            printchooses(elvesarr, contString);
        else if (htpye.equals("halflings"))
            printchooses(halfingsarr, contString);
        else if (htpye.equals("dwarfs"))
            printchooses(dwarfsarr, contString);
        boolean go = true;
        if (contarr.isEmpty()) {
            go = false;
            System.out.println("There is no available abillity");
        }

        while (true) {
            contString = "";

            if (h.getheroname().equals("Oppenent") || y == true) {
                int r = random.nextInt(contarr.size() - 1);
                contString = contarr.get(r);
            } else {
                contString = scanner.next();
            }
            System.out.println("Ability choosed:" + contString);
            System.out.println("----------------------Attacking-----------------------------");
            opp.seedamage(h.getattack());

            if (contString.equals("struggle"))
                contString = "backattack";
            go = false;
            /// Stay away switch case
            if (contString.equals("backattack")) {
                if (map.get("backattack"))
                    backattack(false);
            } else if (contString.equals("shotarrow")) {
                if (map.get("shotarrow"))
                    shotarrow(false);
            }

            else if (contString.equals("blizzard")) {
                if (map.get("blizzard"))
                    blizzard(false);
            } else if (contString.equals("mimic")) {
                if (map.get("mimic"))
                    mimic(false);
            } else if (contString.equals("secbreak")) {
                if (map.get("secbreak"))
                    secbreak();
            } else if (contString.equals("restoremp")) {
                if (map.get("restoremp"))
                    restoremp(false);
            } else if (contString.equals("restorehp")) {
                if (map.get("restorehp"))
                    restorehp(false);
            } else if (contString.equals("thunder")) {
                if (map.get("thunder"))
                    thunder(false);
            } else if (contString.equals("fire")) {
                if (map.get("fire"))
                    fire(false);
            } else if (contString.equals("quickattack")) {
                if (map.get("quickattack"))
                    quicattack(false);
            } else if (contString.equals("burst")) {
                if (map.get("burst"))
                    burst(false);
            } else if (contString.equals("slash")) {
                if (map.get("slash"))
                    slash(false);
            } else {
                System.out.println("Wrong choice!");
                go = true;
            }
            break;

        }
    }

    public void printchooses(String[] arr, String str) throws InterruptedException {
        for (int j = 0; j < arr.length; j++) {
            if (map.get(arr[j]) == true) {
                System.out.println("Enter " + arr[j] + " for using " + arr[j] + " ability (lowercase)");
                contarr.add(arr[j]);
                Thread.sleep(500);
            }
        }
    }

    public int restoremp(boolean x) {// elves,halfings

        if (h.getchp() > 1) {
            if (x == true)
                return 1;
            System.out.println(heroname + " uses restoremp at the cost of " + 2 + "  hp");
            System.out.println(heroname + "'s mp increased' " + 2 * h.getlvl() + "  mp");

            h.setchp(h.getchp() - 2);
            h.setcmp(2 * h.getlvl());
        }
        return 0;
    }

    public int restorehp(boolean x) {// dwarfs,halflings
        if (h.getcmp() > 6) {
            if (x == true)
                return 1;
            System.out.println(heroname + " uses restorehp at the cost of " + 7 + "  mp");
            System.out.println(heroname + "'s hp increased' " + 20 + "  hp");
            h.setchp(h.getchp() + 20);
            h.setcmp(-7);

        }
        return 0;

    }

    public void secbreak() {
        System.out.println(heroname + " uses second breakfast ");
        System.out.println(heroname + "'s mp  and hp increase' " + 5);
        h.setchp(h.getchp() + 5);
        h.setcmp(5);
    }

    public int mimic(boolean x) {
        String[] arr = { "restorehp", "restoremp", "backattack" };

        if (x == true) {

            if (restorehp(true) == 1)
                cont.add("restorehp");

            if (restoremp(true) == 1)
                cont.add("restoremp");

            if (restorehp(true) == 1)
                cont.add("restorehp");
            if (!cont.isEmpty())
                return 1;
            return 0;

        }

        else {
            System.out.println(heroname + " uses mimic ");
            int rand = random.nextInt(cont.size() - 1);
            String randchoose = cont.get(rand);
            if (randchoose.equals("restorehp"))
                restorehp(false);
            else if (randchoose.equals("restoremp"))
                restoremp(false);
            else if (randchoose.equals("backattack"))
                backattack(false);

        }
        return 0;
    }

    public int slash(boolean x) {
        if (h.getcmp() > 4) {
            if (x == true)
                return 1;// control state
            opp.seedamage(h.getattack() * 2);
            h.setcmp(-5);
            System.out.println(heroname + " uses slash at the cost of " + " 5 mp");

        }
        return 0;
    }

    public int burst(boolean x) {
        if (h.getcmp() != 0 && x == true)
            return 1;
        else if (x == true) {
            return 0;
        }
        System.out.println(heroname + " uses burst at the cost of " + h.getcmp() + "  mp");

        opp.seedamage(h.getcmp());
        h.setcmp(-h.getcmp());
        return 0;
    }

    public int quicattack(boolean x) {
        if (h.getcmp() > 1) {
            if (x == true)
                return 1;
            System.out.println(heroname + " uses quick attack at the cost of " + " 2 mp");

            h.setquickattack(true);
            h.setcmp(-2);
            return 0;
        }
        return 0;
    }

    public int shotarrow(boolean x) {
        if (h.getchp() > 2) {

            int estimateddamage = h.getattack() + h.getspeed() + 2;
            if (opp.getchp() > estimateddamage) {
                if (x == true)
                    return 1;
                System.out.println(heroname + " uses shot arrow at the cost of " + " 3 hp");

                opp.seedamage(estimateddamage);
                h.setchp(h.getchp() - 3);
                return 0;
            }
            return 0;
        }
        return 0;
    }

    public int fire(boolean x) {
        int maxspeed = (h.getspeed() >= opp.getspeed()) ? h.getspeed() : opp.getspeed();// find max speed
        if (h.getcmp() > 1) {
            if (x == true)
                return 1;
            h.setcmp(-2);
            System.out.println(heroname + " uses fire at the cost of " + " 2 mp");

            opp.seedamage(3 * maxspeed);
            return 0;
        } else if (h.getchp() > 3) {
            boolean control = opp.controldamage(maxspeed * 3);
            if (control == true) {
                if (x == true)
                    return 1;
                System.out.println(heroname + " uses slash at the cost of " + " 3 hp");
                opp.seedamage(3 * maxspeed);
                h.setchp(h.getchp() - 3);
                return 0;

            }
            return 0;
        }
        return 0;
    }

    public int thunder(boolean x) {
        if (h.getcmp() > 7) {
            if (x == true)
                return 1;
            h.setcmp(-7);
            System.out.println(heroname + " uses thunder at the cost of " + " 8 mp");
            opp.setchp(opp.getchp() - (h.getmagic() * 2));
            return 0;
        }
        return 0;
    }

    public int blizzard(boolean x) {
        int spendchp = 0, spendcmp = 0;
        int oppspendchp = 0, oppspendcmp = 0;
        int remain;
        if (((h.getchp() + h.getcmp() > 12) && x == true))
            return 1;
        System.out.println(heroname + " uses bllizard");

        if (opp.getcmp() > 11) {

            spendcmp = 12;
            h.setcmp(-12);

        } else {
            spendcmp = opp.getcmp();
            remain = 12 - opp.getcmp();
            h.setcmp(-opp.getcmp());
            h.setchp(h.getchp() - remain);
            spendchp = remain;
            opp.seedamage(12);
        }
        if (opp.getchp() > 0) {
            if (h.getcmp() > 11) {
                oppspendcmp = 12;
                opp.setcmp(-12);
            } else {
                oppspendcmp = opp.getcmp();
                remain = 12 - opp.getcmp();
                oppspendchp = remain;
                opp.setcmp(-opp.getcmp());
                opp.setchp(opp.getchp() - remain);
                h.seedamage(12);
            }
        }

        System.out.println("Spend" + heroname + "'s Hp:" + spendchp);
        System.out.println("Spend" + heroname + "'s Mp:" + spendcmp);
        System.out.println("Spend" + oppname + "'s Hp:" + oppspendchp);
        System.out.println("Spend" + oppname + "'s Mp:" + oppspendcmp);
        return 1;

    }
}