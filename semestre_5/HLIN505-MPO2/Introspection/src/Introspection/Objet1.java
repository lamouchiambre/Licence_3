package Introspection;

public class Objet1 {
	private String name;
	private Integer code;
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public Integer getCode() {
		return code;
	}
	public void setCode(Integer code) {
		this.code = code;
	}
	public Objet1(String name, Integer code) {
		this.name = name;
		this.code = code;
	}
	
}
