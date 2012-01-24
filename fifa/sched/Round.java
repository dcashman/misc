package sched;

public class Round{

    /*
     * Round constructor, just holds values
     */
    public Round(){
        left="Boosh";
        playerArray=new String[8];
        num=-1;
    }

    /*
     * Round constructor, just holds values, but initializes to given ones
     */
    public Round(String left, String[] playaz, int num){
        this.left=left;
        playerArray=new String[num];
        for(int i=0;i<num;i++){
            this.playerArray[i]=playaz[i];
	}
        this.num=num;
    }   

    public String left;
    public String[] playerArray;
    public int num;
}