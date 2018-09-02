class ComparablePair implements Comparable<ComparablePair> {
  private int x;
  private int y;

  public ComparablePair(int x, int y) {
    this.x = x;
    this.y = y;
  }
  public int getX(){
      return x;
  }
  public int getY(){
      return y;
  }
  @Override
  public int compareTo(ComparablePair cp) {
    int cpX = cp.getX();
    int cpY = cp.getY();
    // Should not reach here 
    
    if (this.getX()+this.getY() < cpX+cpY) {
      return 1;
    }

    if (this.getX()+this.getY() > cpX+cpY) {
      return -1;
    }

    if (this.getX()+this.getY() == cpX+cpY) {
      return 0;
    }
     
    // Should not reach here 
    return 0;      
  }
}
class Solution {
    public List<int[]> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        int n=nums1.length,m=nums2.length;
        n=Math.min(n,k);
        m=Math.min(m,k);
        Queue<ComparablePair> Q = new PriorityQueue<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){ 
                Q.add(new ComparablePair(nums1[i], nums2[j]));
                if(Q.size()>k) Q.remove();
            }
        
        }        
        List<int[]>ans=new ArrayList<int[]>() ;
        while (Q.peek() != null) {
            ComparablePair p=Q.peek();
            int[] result = new int[2];
            result[0]=p.getX();
            result[1]=p.getY();
            ans.add(result);
            Q.remove();
        }
        return ans;
    }
}
