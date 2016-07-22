package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.List;

//û�п��Ǵ���
public class AdditiveNumber2 {
	
	private List<List<Long>> allRes = new ArrayList<List<Long>>();
    public boolean isAdditiveNumber(String num) {
        help(num,new ArrayList<Long>(),0);  
        return allRes.size()>0;
       
    }

	private void help(String num, ArrayList<Long> res, int pos) {
		if(pos==num.length()){//
			int size = res.size();
			if(size>=3){
				if(res.get(size-1)==res.get(size-2)+res.get(size-3)){//����жϿ��Բ�Ҫ
					allRes.add(res);
				}
			}
		}
		for(int i=pos;i<num.length();i++){
			if(i!=pos&&num.charAt(pos)=='0'){//��λ���Ŀ�ͷ����Ϊ��
				break;
			}
			long val = Long.valueOf(num.substring(pos, i+1));
			int size = res.size();	
			if(size<2){		
				res.add(val);
				help(num, new ArrayList(res),i+1);
				res.remove(res.get(res.size()-1));//�����һ����ӽ�����Ԫ��ɾ��
			}
			else{
				if(val==res.get(size-1)+res.get(size-2)){
					res.add(val);
					help(num, new ArrayList(res),i+1);
					res.remove(res.get(res.size()-1));//�����һ����ӽ�����Ԫ��ɾ��
				}
			}
		}
		
	}
	
	
}
