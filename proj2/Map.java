import java.io.File;
import java.io.FileNotFoundException;
import java.sql.Date;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.regex.Pattern;

class Map {
    int xsize;
    int ysize;
    int x, y, r, xstart, ystart;
    ArrayList<Path> PathArray;
    cell[][] maparr;

    Map() {
        PathArray = new ArrayList<>();
        maparr = new cell[40][91];
        readMap("Map.txt");
        final File folder = new File("Paths");
        listFilesForFolder(folder);

        System.out.println("For the given sample input, the following are single path files that reach a treasure:");
        processpath();
        System.out.println();
        System.out.println("The following are  path combinations that reach a treasure:");
        processpathcombination();

    }

    public static void main(String[] args) {
        Map map = new Map();
    }

    private cell[][] readMap(String filename) {
        try {
            File myObj = new File(filename);
            Scanner myReader = new Scanner(myObj);
            int xindex = -1;
            while (myReader.hasNextLine()) {
                xindex++;
                String data = myReader.nextLine();
                createcellArray(data, xindex);
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

        return maparr;
    }

    private void createcellArray(String data, int xindex) {
        String[] chararray = data.split("");
        int yindex = -1;
        for (String str : chararray) {
            yindex++;
            if (str.equals("B")) {
                maparr[xindex][yindex] = new cell(false);

            } else if (str.equals(".")) {

                maparr[xindex][yindex] = new cell(true);

            } else if (str.equals("S")) {
                xstart = xindex;
                ystart = yindex;
                maparr[xindex][yindex] = new cell(true);

                maparr[xindex][yindex].setStartingPoint(true);

            } else if (str.equals("T")) {
                maparr[xindex][yindex] = new cell(true);
                maparr[xindex][yindex].setTreasure(true);

            }
        }

    }

    private void createPath(String filename) {
        Path newPath = new Path(filename.split("-")[1].split(Pattern.quote("."))[0]);
        try {
            File myObj = new File("./Paths/" + filename);
            Scanner myReader = new Scanner(myObj);

            while (myReader.hasNextLine()) {

                String data = myReader.nextLine();
                String[] dataarr = data.split(" ");

                newPath.insertmove(data.toCharArray()[0], Integer.valueOf(dataarr[1]));
            }
            PathArray.add(newPath);

            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

    }

    boolean isPathtoTreasure(Path p) {
        HashMap<Character, Integer> pathHashMap = p.getHashMap();
        resetcordinate();
        for (Character c : pathHashMap.keySet()) {
            r = pathHashMap.get(c);
            if (isMovepossible(c)) {

                if (maparr[x][y].getisTreasure()) {
                    return true;
                }

            }

        }
        return false;

    }
    boolean isPathtoTreasurec(Path p,Path o) {
        HashMap<Character, Integer> pathHashMap = p.pathcombine(o);
        resetcordinate();
        for (Character c : pathHashMap.keySet()) {
            r = pathHashMap.get(c);
            if (isMovepossible(c)) {

                if (maparr[x][y].getisTreasure()) {
                    return true;
                }

            }

        }
        return false;

    }

    boolean isMovepossible(char c) {

        if (c == 'N') {
            if (x - r < 0)
                return false;
            if (!maparr[x - r][y].getisWalkable())
                return false;
            else
                x -= r;

        } else if (c == 'S') {
            if (x + r > xsize - 1)
                return false;
            if (!maparr[x + r][y].getisWalkable())
                return false;
            else
                x += r;

        } else if (c == 'W') {
            if (y - r < 0)
                return false;
            if (!maparr[x][y - r].getisWalkable())
                return false;
            else
                y -= r;
        }

        else if (c == 'E') {

            if (y + r > xsize - 1)
                return false;

            if (!maparr[x][y + r].getisWalkable())
                return false;

            else
                y += r;
        }
        return true;
    }

    boolean isWalkable(int x, int y) {

        if (maparr[x][y].getWalkableboole())
            return true;
        return false;

    }

    void processpath() {
        for (Path p : PathArray)
            if (isPathtoTreasure(p))
                System.out.print(p.getName() + ",");

    }

    void resetcordinate() {
        x = xstart;
        y = ystart;
    }

    void checkpathcombination(Path a, Path b) {
       
       if(isPathtoTreasurec(a,b)){
        System.out.print("("+a.getName()+"-"+b.getName()+"),");
       }

    }

    void processpathcombination() {
        for (int i = 0; i < PathArray.size() - 1; i++)
            for (int j = i + 1; j < PathArray.size() - 1; j++) {
                checkpathcombination(PathArray.get(i), PathArray.get(j));
                

            }

    }

    public void listFilesForFolder(final File folder) {
        for (final File fileEntry : folder.listFiles()) {
            createPath(fileEntry.getName());

        }
    }
}