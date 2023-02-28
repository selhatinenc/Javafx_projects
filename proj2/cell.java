public class cell {
    int x,y;
    private boolean isWalkable;
   private boolean isTreasure,isStartingPoint;
    cell(boolean isWalkable){
        this.isWalkable=isWalkable;

    }
    public  boolean getisWalkable(){
        return isWalkable;
    }
   public void setWalkable(boolean x){

        isWalkable=x;
    }
    public  boolean getisTreasure(){
        return isTreasure;
    }
   public void setTreasure(boolean x){

        isTreasure=x;
    }
    public  boolean getisStartingPoint(){
        return isStartingPoint;
    }
   public void setStartingPoint(boolean x){

        isStartingPoint=x;
    }
    

    public boolean getWalkableboole() {
        return isWalkable;
    }
    
}
