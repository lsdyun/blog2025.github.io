import scrapy

class DoubanSpider(scrapy.Spider):
    name = "douban_spider"
    start_urls = [
        'https://movie.douban.com/top250',
    ]

    def start_requests(self):
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36',
            'Referer': 'https://movie.douban.com/',
        }
        for url in self.start_urls:
            yield scrapy.Request(url, headers=headers, callback=self.parse)

    def parse(self, response):
        for movie in response.css('div.item'):
            yield {
                'title': movie.css('span.title::text').get(),
                'rating': movie.css('span.rating_num::text').get(),
                'quote': movie.css('span.inq::text').get(),
            }

        # 处理分页
        next_page = response.css('span.next a::attr(href)').get()
        if next_page is not None:
            yield response.follow(next_page, callback=self.parse)