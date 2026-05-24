import java.util.*;

class StringB {

    static String rev(String s) {
        StringBuilder sb = new StringBuilder(s);
        return sb.reverse().toString();
    }

    static String cha(String s) {
        StringBuilder sb = new StringBuilder(s);
        int left = 0;
        int right = sb.length() - 1;
        while (left < right) {
            char temp = sb.charAt(left);
            sb.setCharAt(left, sb.charAt(right));
            sb.setCharAt(right, temp);
            left++;
            right--;
        }
        return sb.toString();
    }

    static Boolean isPall(String a, String b) {
        return (a.equals(b));
    }

    static int[] vowelCount(String s) {
        int count = 0;
        int conso = 0;
        for (int i = 0; i < s.length(); i++) {
            if (
                s.charAt(i) == 'a' ||
                s.charAt(i) == 'e' ||
                s.charAt(i) == 'i' ||
                s.charAt(i) == 'o' ||
                s.charAt(i) == 'u'
            ) {
                count++;
            } else conso++;
        }
        return new int[] { count, conso };
    }

    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder();
        sb.append("Ayu");
        sb.append("gou");
        String str1 = sb.toString();
        String st2 = new StringBuilder(str1).reverse().toString();
        System.out.println(str1);
        System.out.println(st2);
        System.out.println(isPall(str1, st2));
        System.out.println(vowelCount(str1));
    }
}
