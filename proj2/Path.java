import java.util.HashMap;

public class Path {
    HashMap<Character, Integer> pathhashmap;
    String pathName;

    Path(String name) {
        pathName = name;
        pathhashmap = new HashMap<>();

    }

    public void insertmove(Character c, int r) {
       
        pathhashmap.put(c, r);
    }

    public HashMap<Character, Integer> getHashMap() {
        return pathhashmap;
    }

    public String getName() {
        return pathName;
    }
    public HashMap<Character, Integer> pathcombine(Path p) {
        HashMap<Character, Integer> s = pathhashmap;
       
        s.putAll(p.getHashMap());
       
        return s;
    }


}
