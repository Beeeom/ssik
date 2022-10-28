package com.lecspring.myspring;

import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
//������̼�
//�����Ϸ����ٰ� ����� �˷���
//��ǥ���� ������̼�
//�������̵� deprecated ��...
//MVC�߿��� Controller�� �ش��Ѵٰ� �˷���
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;
@Controller
public class BookController {
	
	//BookService bookService 
	//= new BookServiceImpl();
	@Autowired
	BookService bookService;

	//  /create�� ���� �����ų�
	//�ƴϸ� get������� ���� ��쿡
	//ȣ���
	@RequestMapping(value="/create", 
			method=RequestMethod.GET)
	public ModelAndView create() {
		//book ������ create.jsp�� ������
		//ModelAndView ��ü�� ȭ�鵵 �ѱ�� ���� �ѱ�
		return new ModelAndView("book/create");
	}
	
	//  /create�� ������ �� post������� ���� ��� ȣ���
	//å�� ����� �� ȣ���ϴ� �κ�(insert �����ϰ� ��)
	@RequestMapping(value="/create", 
			method = RequestMethod.POST) 
	public ModelAndView createPost
	(@RequestParam Map<String,Object>map) {
		ModelAndView mav = new ModelAndView();
		System.out.println(map.toString());
		String bookId = this.bookService.create(map);
		if(bookId==null)
			mav.setViewName("redirect:/create");
		else
			mav.setViewName
			("redirect:/detail?bookId="+bookId);
		return mav;
	}
	
	@RequestMapping(value="/detail", 
			method=RequestMethod.GET)
	public ModelAndView detail
	(@RequestParam Map<String,Object> map) {
		Map<String,Object> detailMap = 
				this.bookService.detail(map);
		//ModelAndView : ����������� ����, � ������ ������
		//���� �����ؼ� �� ���� ������.
		ModelAndView mav = new ModelAndView();
		mav.addObject("data", detailMap);
		String bookId = map.get("bookId").toString();
		mav.addObject("bookId", bookId);
		mav.setViewName("/book/detail");
		return mav;
	}
	
	@RequestMapping(value="/update",
			method=RequestMethod.GET)
	public ModelAndView update
	(@RequestParam Map<String,Object> map) {
		Map<String,Object> detailMap =
				this.bookService.detail(map);
		ModelAndView mav = new ModelAndView();
		mav.addObject("data", detailMap);
		System.out.println(detailMap);
		mav.setViewName("/book/update");
		return mav;
	}
	
	@RequestMapping(value="/update",
			method=RequestMethod.POST)
	public ModelAndView updatePost
	(@RequestParam Map<String, Object> map) {
		ModelAndView mav = new ModelAndView();
		boolean isUpdateSuccess 
		= this.bookService.edit(map);
		if(isUpdateSuccess) {
			String bookId=map.get("bookId").toString();
			mav.setViewName
			("redirect:/detail?bookId="+bookId);
		} else {
			mav = this.update(map); //get������� �ٽ� ����
		}
		return mav;
	}
	
	@RequestMapping(value="/delete",
			method= RequestMethod.POST) 
	public ModelAndView deletePost
	(@RequestParam Map<String,Object> map) {
		ModelAndView mav = new ModelAndView();
		boolean isDeleteSuccess =
				this.bookService.remove(map);
		if(isDeleteSuccess) {
			mav.setViewName("redirect:/list");
		} else {
			String bookId 
			= map.get("bookId").toString();
			mav.setViewName
			("redirect:/detail?bookId="
			+bookId);
		}
		return mav;
	}
	
	@RequestMapping(value="list")
	public ModelAndView list
	(@RequestParam Map<String,Object> map) {
		List<Map<String,Object>> list =
				this.bookService.list(map);
		ModelAndView mav = new ModelAndView();
		mav.addObject("data",list);
		
		if(map.containsKey("keyword"))
			mav.addObject("keyword",map.get("keyword"));
		
		
		mav.setViewName("/book/list");
		return mav;
		
	}
	
	
	
	
}











